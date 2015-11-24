#ifndef KVS_ALGORITHM_HPP_
#define KVS_ALGORITHM_HPP_

#include <stdint.h>
#include <utility>
#include <string>

#include <msgpack.hpp>

#include <jubatus/core/framework/mixable_helper.hpp>

namespace jubatus {
namespace core {
namespace kvs {

/**
 * `kvs_diff` is a `diff` object for this KVS service.  See comments of
 * `get_diff` implementation for detailed description.
 *
 * `diff` objects must be able to be serialized by MessagePack, so we
 * list fields to be serialized in `MSGPACK_DEFINE`.
 */
struct kvs_diff {
  int32_t sum_;
  uint32_t size_;

  MSGPACK_DEFINE(sum_, size_);
};

/**
 * The class to implement the acutual algorithm - Update/Analyze/MIX.
 * See the comments for each method implementation for details.
 *
 * This class also holds the model data structure as fields; see below.
 */
class kvs_algorithm {
 public:
  kvs_algorithm()
    : local_sum_(0),
      global_sum_(0),
      global_size_(0) {};
  virtual ~kvs_algorithm() {};

  void put(const std::string& key, int32_t value);
  int32_t get(const std::string& key) const;
  float get_average() const;

  // For MIX:
  // (note: these 4 methods are requirement to use
  //        `linear_mixable_helper`; see below for the details)
  void get_diff(kvs_diff& diff) const;
  void mix(const kvs_diff& lhs, kvs_diff& rhs) const;
  bool put_diff(const kvs_diff& mixed_diff);
  jubatus::core::storage::version get_version() const;

  // For `clear` API:
  void clear();

  // For `get_stauts` API:
  void get_status(std::map<std::string, std::string>& status) const;

  // For `save` / `load` API:
  void pack(jubatus::core::framework::packer& pk) const;
  void unpack(msgpack::object o);

 private:
  typedef std::map<std::string, int32_t> data_t;

  /**
   * `local_data_` holds key-value data added via `put` API.
   */
  data_t local_data_;

  /**
   * `local_sum_` is a sum of values in `local_data_`.  This will be calculated
   * in `put` method.  This value will be aggregated among cluster on MIX.
   */
  int32_t local_sum_;

  /**
   * `global_sum_` and `global_size_` are sum of values / number of entries in
   * the whole cluster (except mine.)  These values will be updated on MIX.
   */
  int32_t global_sum_;
  uint32_t global_size_;

 public:
  MSGPACK_DEFINE(local_data_, local_sum_, global_sum_, global_size_);
};

/**
 * This is an idiom to a automagically create "linear-mixer-capabile" version
 * of `kvs_algorithm` class.  `mixable_kvs` class will be instantiated in the
 * driver layer.
 *
 * `linear_mixable_helper` is a helper class provided by the framework that
 * makes easy to write `get_diff`, `mix` and `put_diff` operations.  Instead
 * of using the helper class, you can write your own raw MIX operations by
 * defining class that inherits `linear_mixable`.
 *
 * Note that `linear_mixable_helper` only enables Linear Mixer.  If you need
 * to MIX your model by Push/Pull Mixer, you need to create a class that
 * inherits `push_mixable`, which defines operations that is different from
 * `linear_mixable`.  You can also inherit both classes at the same time.
 */
typedef jubatus::core::framework::linear_mixable_helper<kvs_algorithm, kvs_diff>
    mixable_kvs;
\
}  // namespace kvs
}  // namespace core
}  // namespace jubatus

#endif  // KVS_ALGORITHM_HPP_
