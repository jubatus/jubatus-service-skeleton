#include "kvs_driver.hpp"

#include <stdint.h>
#include <string>

namespace jubatus {
namespace core {
namespace driver {

kvs_driver::kvs_driver()
  : kvs_(new jubatus::core::kvs::kvs_algorithm()) {
  /*
   * Register the mixable data structure of the model as a MIX target.
   */
  register_mixable(new jubatus::core::kvs::mixable_kvs(kvs_));
}

kvs_driver::~kvs_driver() {}

void kvs_driver::put(const std::string& key, int32_t value) {
  kvs_->put(key, value);
}

int32_t kvs_driver::get(const std::string& key) const {
  return kvs_->get(key);
}

float kvs_driver::get_average() const {
  return kvs_->get_average();
}

void kvs_driver::get_status(std::map<std::string, std::string>& status) const {
  kvs_->get_status(status);
}

void kvs_driver::clear() {
  kvs_->clear();
}

void kvs_driver::pack(jubatus::core::framework::packer& pk) const {
  kvs_->pack(pk);
}

void kvs_driver::unpack(msgpack::object o) {
  kvs_->unpack(o);
}

}  // namespace driver
}  // namespace core
}  // namespace jubatus
