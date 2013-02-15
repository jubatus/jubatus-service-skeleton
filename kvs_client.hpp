// This file is auto-generated from kvs.idl
// *** DO NOT EDIT ***

#ifndef KVS_CLIENT_HPP_
#define KVS_CLIENT_HPP_

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <jubatus/msgpack/rpc/client.h>
#include "kvs_types.hpp"

namespace jubatus {
namespace client {

class kvs {
 public:
  kvs(const std::string& host, uint64_t port, double timeout_sec)
      : c_(host, port) {
    c_.set_timeout(timeout_sec);
  }
  
  bool put(std::string name, std::string key, std::string value) {
    msgpack::rpc::future f = c_.call("put", name, key, value);
    return f.get<bool>();
  }
  
  std::string get(std::string name, std::string key) {
    msgpack::rpc::future f = c_.call("get", name, key);
    return f.get<std::string>();
  }
  
  bool del(std::string name, std::string key) {
    msgpack::rpc::future f = c_.call("del", name, key);
    return f.get<bool>();
  }
  
  bool clear(std::string name) {
    msgpack::rpc::future f = c_.call("clear", name);
    return f.get<bool>();
  }
  
  std::map<std::string, std::map<std::string, std::string> > get_status(
      std::string name) {
    msgpack::rpc::future f = c_.call("get_status", name);
    return f.get<std::map<std::string, std::map<std::string, std::string> > >();
  }
  
  bool save(std::string name, std::string id) {
    msgpack::rpc::future f = c_.call("save", name, id);
    return f.get<bool>();
  }
  
  bool load(std::string name, std::string id) {
    msgpack::rpc::future f = c_.call("load", name, id);
    return f.get<bool>();
  }

 private:
  msgpack::rpc::client c_;
};

}  // namespace client
}  // namespace jubatus

#endif  // KVS_CLIENT_HPP_
