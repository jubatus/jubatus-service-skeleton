// this is automatically generated template header please implement and edit.

#include "kvs_serv.hpp"

using namespace jubatus::framework;

namespace jubatus { namespace server { // do not change
kvs_serv::kvs_serv(const server_argv& a)
  :framework::jubatus_serv(a)
{
  //somemixable* mi = new somemixable;
  //somemixable_.set_model(mi);
  //register_mixable(mi);
}

kvs_serv::~kvs_serv()
{}


//update, cht(2)
bool kvs_serv::put(const std::string& key, const std::string& value)
{}

//analysis, cht(2)
std::string kvs_serv::get(const std::string& key) const
{}

//update, cht(2)
bool kvs_serv::del(const std::string& key)
{}

//update, broadcast
bool kvs_serv::clear()
{}

//analysis, broadcast
std::map<std::string,std::map<std::string,std::string > > kvs_serv::get_status() const
{}

//update, broadcast
bool kvs_serv::save(const std::string& id)
{}

//update, broadcast
bool kvs_serv::load(const std::string& id)
{}

void kvs_serv::after_load(){}
}} // namespace jubatus::server
