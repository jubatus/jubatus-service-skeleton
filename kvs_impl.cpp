// This file is auto-generated from kvs.idl with jenerator version 0.4.5-375-g07d06b7/develop
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <pficommon/lang/shared_ptr.h>

#include <jubatus/server/framework.hpp>
#include "kvs_serv.hpp"

namespace jubatus {
namespace server {

class kvs_impl : public jubatus::server::common::mprpc::rpc_server {
 public:
  explicit kvs_impl(const jubatus::server::framework::server_argv& a):
    rpc_server(a.timeout),
    p_(new jubatus::server::framework::server_helper<kvs_serv>(a, true)) {

    rpc_server::add<bool(std::string, std::string, std::string)>("put",
        pfi::lang::bind(&kvs_impl::put, this, pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<std::string(std::string, std::string)>("get",
        pfi::lang::bind(&kvs_impl::get, this, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string)>("del", pfi::lang::bind(
        &kvs_impl::del, this, pfi::lang::_2));
    rpc_server::add<bool(std::string)>("clear", pfi::lang::bind(
        &kvs_impl::clear, this));

    rpc_server::add<std::string(std::string)>("get_config", pfi::lang::bind(
        &kvs_impl::get_config, this));
    rpc_server::add<bool(std::string, std::string)>("save", pfi::lang::bind(
        &kvs_impl::save, this, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string)>("load", pfi::lang::bind(
        &kvs_impl::load, this, pfi::lang::_2));
    rpc_server::add<std::map<std::string, std::map<std::string, std::string> >(
        std::string)>("get_status", pfi::lang::bind(&kvs_impl::get_status,
        this));
  }

  bool put(const std::string& key, const std::string& value) {
    JWLOCK_(p_);
    return get_p()->put(key, value);
  }

  std::string get(const std::string& key) {
    JRLOCK_(p_);
    return get_p()->get(key);
  }

  bool del(const std::string& key) {
    JWLOCK_(p_);
    return get_p()->del(key);
  }

  bool clear() {
    JWLOCK_(p_);
    return get_p()->clear();
  }

  std::string get_config() {
    JRLOCK_(p_);
    return get_p()->get_config();
  }

  bool save(const std::string& id) {
    JWLOCK_(p_);
    return get_p()->save(id);
  }

  bool load(const std::string& id) {
    JWLOCK_(p_);
    return get_p()->load(id);
  }

  std::map<std::string, std::map<std::string, std::string> > get_status() {
    JRLOCK_(p_);
    return p_->get_status();
  }

  int run() { return p_->start(*this); }
  pfi::lang::shared_ptr<kvs_serv> get_p() { return p_->server(); }

 private:
  pfi::lang::shared_ptr<jubatus::server::framework::server_helper<kvs_serv> > p_;
};

}  // namespace server
}  // namespace jubatus

int main(int argc, char* argv[]) {
  return
    jubatus::server::framework::run_server<jubatus::server::kvs_impl>
      (argc, argv, "kvs");
}
