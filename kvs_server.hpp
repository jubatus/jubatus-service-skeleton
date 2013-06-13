// This file is auto-generated from kvs.idl
// *** DO NOT EDIT ***

#ifndef KVS_SERVER_HPP_
#define KVS_SERVER_HPP_

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <pficommon/lang/bind.h>

#include <jubatus/server/common/mprpc/rpc_server.hpp>
#include "kvs_types.hpp"

namespace jubatus {
namespace server {

template <class Impl>
class kvs : public jubatus::server::common::mprpc::rpc_server {
 public:
  explicit kvs(double timeout_sec) : rpc_server(timeout_sec) {
    Impl* impl = static_cast<Impl*>(this);
    rpc_server::add<bool(std::string, std::string, std::string)>("put",
         pfi::lang::bind(&Impl::put, impl, pfi::lang::_1, pfi::lang::_2,
         pfi::lang::_3));
    rpc_server::add<std::string(std::string, std::string)>("get",
         pfi::lang::bind(&Impl::get, impl, pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string)>("del", pfi::lang::bind(
        &Impl::del, impl, pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<bool(std::string)>("clear", pfi::lang::bind(&Impl::clear,
         impl, pfi::lang::_1));
    rpc_server::add<std::map<std::string, std::map<std::string, std::string> >(
        std::string)>("get_status", pfi::lang::bind(&Impl::get_status, impl,
         pfi::lang::_1));
    rpc_server::add<bool(std::string, std::string)>("save", pfi::lang::bind(
        &Impl::save, impl, pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string)>("load", pfi::lang::bind(
        &Impl::load, impl, pfi::lang::_1, pfi::lang::_2));
  }
};

}  // namespace server
}  // namespace jubatus

#endif  // KVS_SERVER_HPP_
