// This file is auto-generated from kvs.idl

#ifndef KVS_SERV_HPP_
#define KVS_SERV_HPP_

#include <jubatus/server/framework.hpp>
#include <jubatus/server/framework/mixer/mixer_factory.hpp>
#include "kvs_types.hpp"

namespace jubatus {
namespace server {

class kvs_serv : public jubatus::server::framework::server_base {  // do not change
 public:
  kvs_serv(
    const jubatus::server::framework::server_argv& a,
    const pfi::lang::shared_ptr<common::lock_service>& zk);  // do not change
  virtual ~kvs_serv();  // do not change

  virtual framework::mixer::mixer* get_mixer() const;
  pfi::lang::shared_ptr<core::framework::mixable_holder> get_mixable_holder() const;
  void get_status(status_t& status) const;

  bool put(const std::string& key, const std::string& value);
  std::string get(const std::string& key) const;
  bool del(const std::string& key);
  bool clear();

  bool set_config(const std::string& config);

 private:
  pfi::lang::scoped_ptr<framework::mixer::mixer> mixer_;
  pfi::lang::shared_ptr<core::framework::mixable_holder> mixable_holder_;

  // add user data here like: pfi::lang::shared_ptr<some_type> some_;
  typedef std::map<std::string,std::string> kvs_map_t;
  kvs_map_t data_;
};

}  // namespace server
}  // namespace jubatus

#endif  // KVS_SERV_HPP_
