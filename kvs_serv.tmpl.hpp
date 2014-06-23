// This file is auto-generated from kvs.idl with jenerator version 0.5.4-224-g49229fa/develop

#ifndef KVS_SERV_TMPL_HPP_
#define KVS_SERV_TMPL_HPP_

#include <string>
#include <jubatus/server/framework.hpp>
#include "kvs_types.hpp"

namespace jubatus {
namespace server {

class kvs_serv : public jubatus::server::framework::server_base {  // do not change
 public:
  kvs_serv(
    const jubatus::server::framework::server_argv& a,
    const jubatus::util::lang::shared_ptr<jubatus::server::common::lock_service>& zk);  // do not change
  virtual ~kvs_serv();  // do not change

  virtual jubatus::server::framework::mixer::mixer* get_mixer() const;
  virtual jubatus::core::driver::driver_base* get_driver() const;
  std::string get_config() const;
  uint64_t user_data_version() const;
  void get_status(status_t& status) const;
  void set_config(const std::string& config);

  bool put(const std::string& key, const std::string& value);
  std::string get(const std::string& key) const;
  bool del(const std::string& key);
  bool clear();

 private:
  // add user defined driver like: jubatus::util::lang::shared_ptr<some_type> some_;
};

}  // namespace server
}  // namespace jubatus

#endif  // KVS_SERV_TMPL_HPP_
