// this is automatically generated template header please implement and edit.

#include "kvs_serv.hpp"

using namespace jubatus::framework;

namespace jubatus { namespace server { // do not change
kvs_serv::kvs_serv(const server_argv& a,
                   const jubatus::common::cshared_ptr<jubatus::common::lock_service>& zk)
  :server_base(a)
{
  mixer_.reset(mixer::create_mixer(a, zk));

  mixable_holder_.reset(new mixable_holder());
  mixer_->set_mixable_holder(mixable_holder_);

  data_ = kvs_map_t();
}

kvs_serv::~kvs_serv()
{}

//update, cht(2)
bool kvs_serv::put(const std::string& key, const std::string& value)
{
    if (data_.count(key) == 0) {
        data_.insert(std::make_pair(key, value));
        return true;
    }
    return false;
}

//analysis, cht(2)
std::string kvs_serv::get(const std::string& key) const
{
    kvs_map_t::const_iterator it = data_.find(key);
    if (it == data_.end()) {
        throw std::runtime_error("key not found");
    }
    return it->second;
}

//update, cht(2)
bool kvs_serv::del(const std::string& key)
{
    data_.erase(key);
    return true;
}

//update, broadcast
bool kvs_serv::clear()
{
    data_.clear();
    return true;
}

//analysis, broadcast
void kvs_serv::get_status(status_t& status) const
{
    std::stringstream ss;
    ss << data_.size();
    status.insert(std::make_pair("size", ss.str()));
}

}} // namespace jubatus::server
