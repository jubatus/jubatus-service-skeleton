// this is automatically generated template header please implement and edit.
#pragma once
#include <jubatus/framework.hpp>
#include <jubatus/framework/mixer/mixer_factory.hpp>
#include "kvs_types.hpp"
using namespace jubatus::framework;

namespace jubatus { namespace server { // do not change
class kvs_serv : public server_base // do not change
{
public:
  kvs_serv(const server_argv& a,
           const jubatus::common::cshared_ptr<jubatus::common::lock_service>& zk); // do not change
  virtual ~kvs_serv(); // do not change

  mixer::mixer* get_mixer() const {
    return mixer_.get();
  }

  pfi::lang::shared_ptr<framework::mixable_holder> get_mixable_holder() const {
    return mixable_holder_;
  }

  bool put(const std::string& key, const std::string& value); //update cht(2)

  std::string get(const std::string& key) const; //analysis cht(2)

  bool del(const std::string& key); //update cht(2)

  bool clear(); //update broadcast

  void get_status(status_t& status) const; //analysis broadcast

private:
  pfi::lang::scoped_ptr<framework::mixer::mixer> mixer_;
  pfi::lang::shared_ptr<framework::mixable_holder> mixable_holder_;

  // add user data here like: pfi::lang::shared_ptr<some_type> some_;
  typedef std::map<std::string,std::string> kvs_map_t;
  kvs_map_t data_;
};
}} // namespace jubatus::server
