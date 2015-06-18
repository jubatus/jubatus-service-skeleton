// This file is auto-generated from kvs.idl with jenerator version 0.6.4-146-g79178f8/develop
// *** DO NOT EDIT ***

#ifndef KVS_CLIENT_HPP_
#define KVS_CLIENT_HPP_

#include <map>
#include <string>
#include <vector>
#include <jubatus/client/common/client.hpp>
#include <jubatus/client/common/datum.hpp>
#include "kvs_types.hpp"

namespace jubatus {
namespace client {

class kvs : public jubatus::client::common::client {
 public:
  kvs(const std::string& host, uint64_t port, const std::string& name,
      unsigned int timeout_sec)
      : client(host, port, name, timeout_sec) {
  }

  bool put(const std::string& key, const std::string& value) {
    msgpack::rpc::future f = c_.call("put", name_, key, value);
    return f.get<bool>();
  }

  std::string get(const std::string& key) {
    msgpack::rpc::future f = c_.call("get", name_, key);
    return f.get<std::string>();
  }

  bool del(const std::string& key) {
    msgpack::rpc::future f = c_.call("del", name_, key);
    return f.get<bool>();
  }

  bool clear() {
    msgpack::rpc::future f = c_.call("clear", name_);
    return f.get<bool>();
  }
};

}  // namespace client
}  // namespace jubatus

#endif  // KVS_CLIENT_HPP_
