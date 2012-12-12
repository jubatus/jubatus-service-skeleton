
#include "kvs_types.hpp"
#include <pficommon/network/mprpc.h>


namespace jubatus {

namespace client {

class kvs : public pfi::network::mprpc::rpc_client {
public:
  kvs(const std::string &host, uint64_t port, double timeout_sec)
    : rpc_client(host, port, timeout_sec) {}

    bool put(std::string name, std::string key, std::string value) {
      return call<bool(std::string, std::string, std::string)>("put")(name, key, value);
    }

    std::string get(std::string name, std::string key) {
      return call<std::string(std::string, std::string)>("get")(name, key);
    }

    bool del(std::string name, std::string key) {
      return call<bool(std::string, std::string)>("del")(name, key);
    }

    bool clear(std::string name) {
      return call<bool(std::string)>("clear")(name);
    }

    std::map<std::string, std::map<std::string, std::string > > get_status(std::string name) {
      return call<std::map<std::string, std::map<std::string, std::string > >(std::string)>("get_status")(name);
    }

    bool save(std::string name, std::string id) {
      return call<bool(std::string, std::string)>("save")(name, id);
    }

    bool load(std::string name, std::string id) {
      return call<bool(std::string, std::string)>("load")(name, id);
    }

private:
};

} // namespace client

} // namespace jubatus

