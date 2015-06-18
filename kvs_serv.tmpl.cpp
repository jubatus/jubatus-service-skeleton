// This file is auto-generated from kvs.idl with jenerator version 0.6.4-146-g79178f8/develop

#include "kvs_serv.hpp"

namespace jubatus {
namespace server {

kvs_serv::kvs_serv(
  const jubatus::server::framework::server_argv& a,
  const jubatus::util::lang::shared_ptr<jubatus::server::common::lock_service>& zk)
    : jubatus::server::framework::server_base(a) {
}

kvs_serv::~kvs_serv() {
}

jubatus::server::framework::mixer::mixer* kvs_serv::get_mixer() const {
}

jubatus::core::driver::driver_base* kvs_serv::get_driver() const {
}

std::string kvs_serv::get_config() const {
}

uint64_t kvs_serv::user_data_version() const {
}

void kvs_serv::get_status(status_t& status) const {
}

void kvs_serv::set_config(const std::string& config) {
}

bool kvs_serv::put(const std::string& key, const std::string& value) {
}

std::string kvs_serv::get(const std::string& key) const {
}

bool kvs_serv::del(const std::string& key) {
}

bool kvs_serv::clear() {
}

}  // namespace server
}  // namespace jubatus
