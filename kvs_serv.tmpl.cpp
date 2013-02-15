// This file is auto-generated from kvs.idl
// *** DO NOT EDIT ***

#include "kvs_serv.hpp"

namespace jubatus {
namespace server {

kvs_serv::kvs_serv(const jubatus::framework::server_argv& a)
    : jubatus::framework::jubatus_serv(a) {
  // somemixable* mi = new somemixable;
  // somemixable_.set_model(mi);
  // register_mixable(mi);
}

kvs_serv::~kvs_serv() {
}

bool kvs_serv::put(const std::string& key, const std::string& value) {
}

std::string kvs_serv::get(const std::string& key) const {
}

bool kvs_serv::del(const std::string& key) {
}

bool kvs_serv::clear() {
}

std::map<std::string, std::map<std::string, std::string> > kvs_serv::get_status(
    ) const {
}

bool kvs_serv::save(const std::string& id) {
}

bool kvs_serv::load(const std::string& id) {
}

}  // namespace server
}  // namespace jubatus
