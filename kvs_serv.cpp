#include "kvs_serv.hpp"

#include <jubatus/server/framework/mixer/mixer_factory.hpp>
#include <glog/logging.h>

namespace jubatus {
namespace server {

namespace {

// These parameters are unused; written to show you how to handle config.
// Also see `set_config` method below.

struct kvs_serv_config {
  int param1;
  std::string param2;

  template <typename Ar>
  void serialize(Ar& ar) {
    ar
        & JUBA_MEMBER(param1)
        & JUBA_MEMBER(param2);
  }
};
}

kvs_serv::kvs_serv(
  const jubatus::server::framework::server_argv& a,
  const jubatus::util::lang::shared_ptr<jubatus::server::common::lock_service>& zk)
    : jubatus::server::framework::server_base(a) {
  mixer_.reset(server::framework::mixer::create_mixer(a, zk, rw_mutex()));

  data_ = kvs_map_t();
}

kvs_serv::~kvs_serv() {
}

jubatus::server::framework::mixer::mixer* kvs_serv::get_mixer() const {
  return mixer_.get();
}

jubatus::core::driver::driver_base* kvs_serv::get_driver() const {
  // TODO: return pointer of driver_base
  return NULL;
}

std::string kvs_serv::get_config() const {
  return config_;
}

uint64_t kvs_serv::user_data_version() const {
  return 1u;
}

void kvs_serv::get_status(status_t& status) const {
  std::stringstream ss;
  ss << data_.size();
  status.insert(std::make_pair("size", ss.str()));
}

void kvs_serv::set_config(const std::string& config) {
  core::common::jsonconfig::config config_root(
      jubatus::util::lang::lexical_cast<jubatus::util::text::json::json>(config));
  kvs_serv_config conf =
    core::common::jsonconfig::config_cast_check<kvs_serv_config>(config_root);
  config_ = config;

  // You can use configuration values here
  LOG(INFO) << "param1 = " << conf.param1;
  LOG(INFO) << "param2 = " << conf.param2;
}

bool kvs_serv::put(const std::string& key, const std::string& value) {
  if (data_.count(key) == 0) {
    data_.insert(std::make_pair(key, value));
    return true;
  }
  return false;
}

std::string kvs_serv::get(const std::string& key) const {
  kvs_map_t::const_iterator it = data_.find(key);
  if (it == data_.end()) {
    throw std::runtime_error("key not found");
  }
  return it->second;
}

bool kvs_serv::del(const std::string& key) {
  data_.erase(key);
  return true;
}

bool kvs_serv::clear() {
  data_.clear();
  return true;
}

}  // namespace server
}  // namespace jubatus
