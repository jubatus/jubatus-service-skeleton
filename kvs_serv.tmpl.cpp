// This file is auto-generated from kvs.idl

#include "kvs_serv.hpp"

namespace jubatus {
namespace server {

kvs_serv::kvs_serv(
  const jubatus::framework::server_argv& a,
  const common::cshared_ptr<common::lock_service>& zk)
    : jubatus::framework::server_base(a) {
  // somemixable* mi = new somemixable;
  // somemixable_.set_model(mi);
  // get_mixable_holder()->register_mixable(mi);
}

kvs_serv::~kvs_serv() {
}

virtual mixer::mixer* kvs_serv::get_mixer() const {
}

pfi::lang::shared_ptr<framework::mixable_holder> kvs_serv::get_mixable_holder(
    ) const {
}

void kvs_serv::get_status(status_t& status) const {
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
