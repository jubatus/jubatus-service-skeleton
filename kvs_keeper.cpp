// This file is auto-generated from kvs.idl
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>

#include <glog/logging.h>

#include <jubatus/core/common/exception.hpp>
#include <jubatus/server/framework/aggregators.hpp>
#include <jubatus/server/framework/keeper.hpp>
#include "kvs_types.hpp"

namespace jubatus {

int run_keeper(int argc, char* argv[]) {
  try {
    jubatus::server::framework::keeper k(
        jubatus::server::framework::keeper_argv(argc, argv, "kvs"));
    k.register_async_cht<2, bool, std::string>("put", pfi::lang::function<bool(
        bool, bool)>(&jubatus::server::framework::all_and));
    k.register_async_cht<2, std::string>("get", pfi::lang::function<std::string(
        std::string, std::string)>(&jubatus::server::framework::pass<std::string>));
    k.register_async_cht<2, bool>("del", pfi::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
    k.register_async_broadcast<bool>("clear", pfi::lang::function<bool(bool,
         bool)>(&jubatus::server::framework::all_and));
    k.register_async_broadcast<std::map<std::string, std::map<std::string,
         std::string> > >("get_status",
         pfi::lang::function<std::map<std::string, std::map<std::string,
         std::string> >(std::map<std::string, std::map<std::string,
         std::string> >, std::map<std::string, std::map<std::string,
         std::string> >)>(&jubatus::server::framework::merge<std::string,
         std::map<std::string, std::string> >));
    k.register_async_broadcast<bool, std::string>("save",
         pfi::lang::function<bool(bool, bool)>(&jubatus::server::framework::all_and));
    k.register_async_broadcast<bool, std::string>("load",
         pfi::lang::function<bool(bool, bool)>(&jubatus::server::framework::all_and));
    return k.run();
  } catch (const jubatus::core::common::exception::jubatus_exception& e) {
    LOG(FATAL) << e.diagnostic_information(true);
    return -1;
  }
}

}  // namespace jubatus

int main(int argc, char* argv[]) {
  jubatus::run_keeper(argc, argv);
}
