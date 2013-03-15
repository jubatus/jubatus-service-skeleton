// This file is auto-generated from kvs.idl
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>

#include <jubatus/framework.hpp>
#include "kvs_server.hpp"
#include "kvs_serv.hpp"

namespace jubatus {
namespace server {

class kvs_impl_ : public kvs<kvs_impl_> {
 public:
  explicit kvs_impl_(const jubatus::framework::server_argv& a):
    kvs<kvs_impl_>(a.timeout),
    p_(new jubatus::framework::server_helper<kvs_serv>(a, true)) {
  }
  bool put(std::string name, std::string key, std::string value) {
    JWLOCK__(p_);
    return get_p()->put(key, value);
  }

  std::string get(std::string name, std::string key) {
    JRLOCK__(p_);
    return get_p()->get(key);
  }

  bool del(std::string name, std::string key) {
    JWLOCK__(p_);
    return get_p()->del(key);
  }

  bool clear(std::string name) {
    JWLOCK__(p_);
    return get_p()->clear();
  }

  std::map<std::string, std::map<std::string, std::string> > get_status(
      std::string name) {
    JRLOCK__(p_);
    return p_->get_status();
  }

  bool save(std::string name, std::string id) {
    JWLOCK__(p_);
    return get_p()->save(id);
  }

  bool load(std::string name, std::string id) {
    JWLOCK__(p_);
    return get_p()->load(id);
  }
  int run() { return p_->start(*this); }
  common::cshared_ptr<kvs_serv> get_p() { return p_->server(); }

 private:
  common::cshared_ptr<jubatus::framework::server_helper<kvs_serv> > p_;
};

}  // namespace server
}  // namespace jubatus

int main(int argc, char* argv[]) {
  return
    jubatus::framework::run_server<jubatus::server::kvs_impl_>
      (argc, argv, "kvs");
}
