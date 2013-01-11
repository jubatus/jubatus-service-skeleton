
// This file is auto-generated from kvs.idl
// *** DO NOT EDIT ***

#ifndef KVS_SERVER_HPP_
#define KVS_SERVER_HPP_


#include "kvs_types.hpp"
#include <jubatus/common/mprpc/rpc_server.hpp>
#include <pficommon/lang/bind.h>


namespace jubatus {

namespace server {

template <class Impl>
class kvs : public jubatus::common::mprpc::rpc_server {
public:
  kvs(double timeout_sec): rpc_server(timeout_sec) {

    rpc_server::add<bool(std::string, std::string, std::string) >("put", pfi::lang::bind(&Impl::put, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<std::string(std::string, std::string) >("get", pfi::lang::bind(&Impl::get, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string) >("del", pfi::lang::bind(&Impl::del, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<bool(std::string) >("clear", pfi::lang::bind(&Impl::clear, static_cast<Impl*>(this), pfi::lang::_1));
    rpc_server::add<std::map<std::string, std::map<std::string, std::string > >(std::string) >("get_status", pfi::lang::bind(&Impl::get_status, static_cast<Impl*>(this), pfi::lang::_1));
    rpc_server::add<bool(std::string, std::string) >("save", pfi::lang::bind(&Impl::save, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string) >("load", pfi::lang::bind(&Impl::load, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
  }
};

} // namespace server

} // namespace jubatus



#endif // KVS_SERVER_HPP_
