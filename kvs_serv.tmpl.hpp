// This file is auto-generated from kvs.idl
// *** DO NOT EDIT ***

#ifndef KVS_SERV_TMPL_HPP_
#define KVS_SERV_TMPL_HPP_

#include <jubatus/framework.hpp>
#include "kvs_types.hpp"

namespace jubatus {
namespace server {

class kvs_serv : public jubatus::framework::jubatus_serv {  // do not change
 public:
  kvs_serv(const jubatus::framework::server_argv& a);  // do not change
  virtual ~kvs_serv();  // do not change
  bool put(const std::string& key, const std::string& value);
  std::string get(const std::string& key) const;
  bool del(const std::string& key);
  bool clear();
  std::map<std::string, std::map<std::string, std::string> > get_status() const;
  bool save(const std::string& id);
  bool load(const std::string& id);

 private:
  // add user data here like: pfi::lang::shared_ptr<some_type> some_;
};

}  // namespace server
}  // namespace jubatus

#endif  // KVS_SERV_TMPL_HPP_
