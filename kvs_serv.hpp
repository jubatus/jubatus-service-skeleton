#ifndef KVS_SERV_HPP_
#define KVS_SERV_HPP_

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
  jubatus::util::lang::shared_ptr<jubatus::core::framework::mixable_holder> get_mixable_holder() const;
  std::string get_config() const;
  uint64_t user_data_version() const;
  void get_status(status_t& status) const;
  void set_config(const std::string& config);

  bool put(const std::string& key, const std::string& value);
  std::string get(const std::string& key) const;
  bool del(const std::string& key);
  bool clear();

 private:
  // add user data here like: jubatus::util::lang::shared_ptr<some_type> some_;
  jubatus::util::lang::scoped_ptr<framework::mixer::mixer> mixer_;
  jubatus::util::lang::shared_ptr<core::framework::mixable_holder> mixable_holder_;

  typedef std::map<std::string,std::string> kvs_map_t;
  kvs_map_t data_;
  std::string config_;
};

}  // namespace server
}  // namespace jubatus

#endif  // KVS_SERV_HPP_
