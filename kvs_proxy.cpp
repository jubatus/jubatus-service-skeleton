// This file is auto-generated from kvs.idl with jenerator version 0.6.4-146-g79178f8/develop
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
    k.register_async_cht<2, bool, std::string>("put",
        jubatus::util::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
    k.register_async_cht<2, std::string>("get",
        jubatus::util::lang::function<std::string(std::string, std::string)>(
        &jubatus::server::framework::pass<std::string>));
    k.register_async_cht<2, bool>("del", jubatus::util::lang::function<bool(
        bool, bool)>(&jubatus::server::framework::all_and));
    k.register_async_broadcast<bool>("clear",
        jubatus::util::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
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
