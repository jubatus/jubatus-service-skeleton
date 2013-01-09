
// This file is auto-generated from kvs.idl
// *** DO NOT EDIT ***

#ifndef KVS_CLIENT_HPP_
#define KVS_CLIENT_HPP_


#include "kvs_types.hpp"
#include <jubatus/msgpack/rpc/client.h>


namespace jubatus {

namespace client {

class kvs {
public:
  kvs(const std::string &host, uint64_t port, double timeout_sec)
    : c_(host, port) {
    c_.set_timeout( timeout_sec );
  }

    bool put(std::string name, std::string key, std::string value) {
      return c_.call("put", name, key, value).get<bool >();
    }

    std::string get(std::string name, std::string key) {
      return c_.call("get", name, key).get<std::string >();
    }

    bool del(std::string name, std::string key) {
      return c_.call("del", name, key).get<bool >();
    }

    bool clear(std::string name) {
      return c_.call("clear", name).get<bool >();
    }

    std::map<std::string, std::map<std::string, std::string > > get_status(std::string name) {
      return c_.call("get_status", name).get<std::map<std::string, std::map<std::string, std::string > > >();
    }

    bool save(std::string name, std::string id) {
      return c_.call("save", name, id).get<bool >();
    }

    bool load(std::string name, std::string id) {
      return c_.call("load", name, id).get<bool >();
    }

private:
  msgpack::rpc::client c_;
};

} // namespace client

} // namespace jubatus



#endif // KVS_CLIENT_HPP_
