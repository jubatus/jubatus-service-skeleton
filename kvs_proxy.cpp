// This file is auto-generated from kvs.idl with jenerator version 0.8.1-11-g6aaff17/master
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>

#include <jubatus/core/common/exception.hpp>
#include <jubatus/server/common/logger/logger.hpp>
#include <jubatus/server/framework/aggregators.hpp>
#include <jubatus/server/framework/proxy.hpp>
#include "kvs_types.hpp"

namespace jubatus {

int run_proxy(int argc, char* argv[]) {
  try {
    jubatus::server::framework::proxy k(
        jubatus::server::framework::proxy_argv(argc, argv, "kvs"));
    k.register_async_cht<1, bool, int32_t>("put",
        jubatus::util::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::pass<bool>));
    k.register_async_cht<1, entry>("get", jubatus::util::lang::function<entry(
        entry, entry)>(&jubatus::server::framework::pass<entry>));
    k.register_async_random<float>("get_average");
    return k.run();
  } catch (const jubatus::core::common::exception::jubatus_exception& e) {
    LOG(FATAL) << "exception in proxy main thread: "
               << e.diagnostic_information(true);
    return -1;
  }
}

}  // namespace jubatus

int main(int argc, char* argv[]) {
  return jubatus::run_proxy(argc, argv);
}
