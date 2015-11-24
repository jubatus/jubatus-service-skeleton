// This file is auto-generated from kvs.idl with jenerator version 0.8.1-11-g6aaff17/master
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>
#include "jubatus/util/lang/shared_ptr.h"

#include <jubatus/server/framework.hpp>
#include "kvs_serv.hpp"

namespace jubatus {
namespace server {

class kvs_impl : public jubatus::server::common::mprpc::rpc_server {
 public:
  explicit kvs_impl(const jubatus::server::framework::server_argv& a):
    rpc_server(a.timeout),
    p_(new jubatus::server::framework::server_helper<kvs_serv>(a, true)) {

    rpc_server::add<bool(std::string, std::string, int32_t)>("put",
        jubatus::util::lang::bind(&kvs_impl::put, this, jubatus::util::lang::_2,
        jubatus::util::lang::_3));
    rpc_server::add<entry(std::string, std::string)>("get",
        jubatus::util::lang::bind(&kvs_impl::get, this,
        jubatus::util::lang::_2));
    rpc_server::add<float(std::string)>("get_average",
        jubatus::util::lang::bind(&kvs_impl::get_average, this));

    rpc_server::add<std::string(std::string)>("get_config",
        jubatus::util::lang::bind(&kvs_impl::get_config, this));
    rpc_server::add<std::map<std::string, std::string>(std::string,
        std::string)>("save", jubatus::util::lang::bind(&kvs_impl::save, this,
        jubatus::util::lang::_2));
    rpc_server::add<bool(std::string, std::string)>("load",
        jubatus::util::lang::bind(&kvs_impl::load, this,
        jubatus::util::lang::_2));
    rpc_server::add<std::map<std::string, std::map<std::string, std::string> >(
        std::string)>("get_status", jubatus::util::lang::bind(
        &kvs_impl::get_status, this));
  }

  bool put(const std::string& key, int32_t value) {
    JWLOCK_(p_);
    return get_p()->put(key, value);
  }

  entry get(const std::string& key) {
    JRLOCK_(p_);
    return get_p()->get(key);
  }

  float get_average() {
    JRLOCK_(p_);
    return get_p()->get_average();
  }

  std::string get_config() {
    JRLOCK_(p_);
    return get_p()->get_config();
  }

  std::map<std::string, std::string> save(const std::string& id) {
    JRLOCK_(p_);
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
  jubatus::util::lang::shared_ptr<kvs_serv> get_p() { return p_->server(); }

 private:
  jubatus::util::lang::shared_ptr<jubatus::server::framework::server_helper<kvs_serv> > p_;
};

}  // namespace server
}  // namespace jubatus

int main(int argc, char* argv[]) {
  return
    jubatus::server::framework::run_server<jubatus::server::kvs_impl>
      (argc, argv, "kvs");
}
