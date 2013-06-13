// This file is auto-generated from kvs.idl

#include "kvs_serv.hpp"

namespace jubatus {
namespace server {

kvs_serv::kvs_serv(
  const jubatus::server::framework::server_argv& a,
  const pfi::lang::shared_ptr<jubatus::server::common::lock_service>& zk)
    : jubatus::server::framework::server_base(a) {
  // somemixable* mi = new somemixable;
  // somemixable_.set_model(mi);
  // get_mixable_holder()->register_mixable(mi);
}

kvs_serv::~kvs_serv() {
}

jubatus::server::framework::mixer::mixer* kvs_serv::get_mixer() const {
}

pfi::lang::shared_ptr<jubatus::core::framework::mixable_holder> kvs_serv::get_mixable_holder() const {
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
