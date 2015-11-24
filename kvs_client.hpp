// This file is auto-generated from kvs.idl with jenerator version 0.8.1-11-g6aaff17/master
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

  bool put(const std::string& key, int32_t value) {
    msgpack::rpc::future f = c_.call("put", name_, key, value);
    return f.get<bool>();
  }

  entry get(const std::string& key) {
    msgpack::rpc::future f = c_.call("get", name_, key);
    return f.get<entry>();
  }

  float get_average() {
    msgpack::rpc::future f = c_.call("get_average", name_);
    return f.get<float>();
  }
};

}  // namespace client
}  // namespace jubatus

#endif  // KVS_CLIENT_HPP_
