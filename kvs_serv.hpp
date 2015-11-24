// This file is modified based on the jenerated template file

#ifndef KVS_SERV_HPP_
#define KVS_SERV_HPP_

#include <string>

#include <jubatus/server/framework.hpp>

#include "kvs_driver.hpp"
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

  bool put(const std::string& key, int32_t value);
  entry get(const std::string& key) const;
  float get_average() const;

 private:
  // Driver instance.
  jubatus::util::lang::shared_ptr<jubatus::core::driver::kvs_driver> driver_;

  // Mixer instance.
  jubatus::util::lang::shared_ptr<jubatus::server::framework::mixer::mixer> mixer_;

  // Configuration string passed via `set_config` API.
  std::string config_;
};

}  // namespace server
}  // namespace jubatus

#endif  // KVS_SERV_HPP_
