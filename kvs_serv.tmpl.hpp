// this is automatically generated template header please implement and edit.
#pragma once
#include <jubatus/framework.hpp>
#include "kvs_types.hpp"
using namespace jubatus::framework;

namespace jubatus { namespace server { // do not change
class kvs_serv : public jubatus_serv // do not change
{
public:
  kvs_serv(const server_argv& a); // do not change
  virtual ~kvs_serv(); // do not change

  bool put(const std::string& key, const std::string& value); //update cht(2)

  std::string get(const std::string& key) const; //analysis cht(2)

  bool del(const std::string& key); //update cht(2)

  bool clear(); //update broadcast

  std::map<std::string,std::map<std::string,std::string > > get_status() const; //analysis broadcast

  bool save(const std::string& id); //update broadcast

  bool load(const std::string& id); //update broadcast
  void after_load();

private:
  // add user data here like: pfi::lang::shared_ptr<some_type> some_;
};
}} // namespace jubatus::server
