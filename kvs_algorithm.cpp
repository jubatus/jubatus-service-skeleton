#include "kvs_algorithm.hpp"

#include <jubatus/util/lang/cast.h>

#include <string>

using jubatus::util::lang::lexical_cast;

namespace jubatus {
namespace core {
namespace kvs {

/**
 * Update: `put` operation adds the specified key-value data to the model.
 * If the key already exists in the model, it will be overwritten.
 */
void kvs_algorithm::put(const std::string& key, int32_t value) {
  /*
   * Check if the key already exists in our model.  If the key exists,
   * preserve the old value to maintain `local_sum_`.
   */
  int32_t old_value = 0;
  if (local_data_.find(key) != local_data_.end()) {
    old_value = local_data_[key];
  }

  /*
   * Update the local model.
   */
  local_data_[key] = value;
  local_sum_ = local_sum_ - old_value + value;
}

/**
 * Analyze: `get` operation returns the value for the specified key in the
 * model.  An exception will be thrown if the key does not exist in the model.
 */
int32_t kvs_algorithm::get(const std::string& key) const {
  data_t::const_iterator it = local_data_.find(key);
  if (it != local_data_.end()) {
    return it->second;
  }
  throw std::out_of_range(key + " not found");
}

/**
 * Analyze: `get_average` operation returns the cluster-wide average of every
 * value.
 */
float kvs_algorithm::get_average() const {
  return (float(global_sum_ + local_sum_) / (global_size_ + local_data_.size()));
}

/**
 * MIX: At the beginning of the MIX session, MIX master server calls `get_diff`
 * for every member servers in the cluster.  This method will be invoked by the
 * framework when `get_diff` RPC API is called.
 * This method is expected to returns `diff` object, which is a "summarized"
 * version of the local model that needs to be shared within the cluster.
 *
 * In this KVS, we share the sum of entry values and number of entries, instead
 * of the actual raw data (`local_data_`), so that every server in the cluster
 * can compute average (in `get_average`) without having all the data.
 */
void kvs_algorithm::get_diff(kvs_diff& diff) const {
  diff.sum_ = local_sum_;
  diff.size_ = local_data_.size();
}

/**
 * MIX: `mix` is a static operation to aggregate two `diff` objects.  MIX is
 * is a fold-left operation; the master server aggregates `diff`s collected
 * from member servers in the clusters by using this method.
 *
 * In this KVS, we just add two values to compute the "sum of sum" and
 * "sum of size".
 */
void kvs_algorithm::mix(const kvs_diff& lhs, kvs_diff& rhs) const {
  rhs.sum_ += lhs.sum_;
  rhs.size_ += lhs.size_;
}

/**
 * MIX: At the end of the MIX session, MIX master server calls `put_diff` for
 * every member servers in the cluster.  This method will be invoked by the
 * framework when `put_diff` RPC API is called.
 * This method is expected to take in the `mixed_diff` (which is a `diff` object
 * created by aggregating `diff`s from every servers) to the local model.
 *
 * In this KVS, we update `global_sum_` and `global_size_` to keep up with the
 * sum of entry values / number of entries from other cluster members.
 */
bool kvs_algorithm::put_diff(const kvs_diff& mixed_diff) {
  global_sum_ = mixed_diff.sum_ - local_sum_;
  global_size_ = mixed_diff.size_ - local_data_.size();

  /*
   * Returning `true` means `put_diff` succeeded.  On failure, return false.
   */
  return true;
}

/**
 * MIX: `get_version` operation is expected to return a sequential revision
 * of the model.  This can be used to ensure that all cluster members have
 * models with the same revision.  If you need to do so, you need to write
 * your own validation code in MIX code above.  See the implementation of
 * `jubatus::core::storage::local_storage_mixture` class in the framework
 * for an example.
 *
 * In this KVS, MIX is an idempotent operation (i.e., even if some server
 * failed to take part in the MIX session, next MIX session will correct
 * the situation), so no revision checking is necessary.  We just return
 * the default model version.
 */
jubatus::core::storage::version kvs_algorithm::get_version() const {
  return jubatus::core::storage::version();
}

/**
 * This method returns KVS-specific status metrics.
 */
void kvs_algorithm::get_status(std::map<std::string, std::string>& status) const {
  status.insert(std::make_pair(
      "local_size", lexical_cast<std::string>(local_data_.size())));
  status.insert(std::make_pair(
      "global_size", lexical_cast<std::string>(global_size_)));
}

/**
 * This method clears the model to the initial state.
 */
void kvs_algorithm::clear() {
  local_data_ = data_t();
  local_sum_ = 0;
  global_sum_ = 0;
  global_size_ = 0;
}

/**
 * This method serializes the model as MessagePack format.
 */
void kvs_algorithm::pack(jubatus::core::framework::packer& pk) const {
  pk.pack(*this);
}

/**
 * This method deserializes the model in MessagePack format.
 */
void kvs_algorithm::unpack(msgpack::object o) {
  o.convert(this);
}

}  // namespace kvs
}  // namespace core
}  // namespace jubatus
