// This file is auto-generated from kvs.idl
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>

#include <glog/logging.h>

#include <jubatus/core/common/exception.hpp>
#include <jubatus/server/framework/aggregators.hpp>
#include <jubatus/server/framework/proxy.hpp>
#include "kvs_types.hpp"

namespace jubatus {

int run_proxy(int argc, char* argv[]) {
  try {
    jubatus::server::framework::proxy k(
        jubatus::server::framework::proxy_argv(argc, argv, "kvs"));
    k.register_async_cht<2, bool, std::string>("put", pfi::lang::function<bool(
        bool, bool)>(&jubatus::server::framework::all_and));
    k.register_async_cht<2, std::string>("get", pfi::lang::function<std::string(
        std::string, std::string)>(
        &jubatus::server::framework::pass<std::string>));
    k.register_async_cht<2, bool>("del", pfi::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
    k.register_async_broadcast<bool>("clear", pfi::lang::function<bool(bool,
        bool)>(&jubatus::server::framework::all_and));
    return k.run();
  } catch (const jubatus::core::common::exception::jubatus_exception& e) {
    LOG(FATAL) << e.diagnostic_information(true);
    return -1;
  }
}

}  // namespace jubatus

int main(int argc, char* argv[]) {
  jubatus::run_proxy(argc, argv);
}
