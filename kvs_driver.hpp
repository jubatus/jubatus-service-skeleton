#ifndef KVS_DRIVER_HPP_
#define KVS_DRIVER_HPP_

#include <stdint.h>

#include <jubatus/core/driver/driver.hpp>

#include "kvs_algorithm.hpp"

namespace jubatus {
namespace core {
namespace driver {

/**
 * Driver is a layer that connects between core algorithm and server layer.
 * This layer is responsible to:
 *   - Do some preprocess needed (e.g., feature extraction) for machine
 *     learning algorithms; as this KVS service does not require any
 *     preprocess, we just forward the method call to the core algorithm
 *     layer.
 *   - Setup model MIX.  Register "mixable" objects (that is a model
 *     data structure being MIXed) to the framework.  This is usually done
 *     in the constructor.
 */
class kvs_driver : public jubatus::core::driver::driver_base {
 public:
  kvs_driver();
  virtual ~kvs_driver();

  /*
   * Following methods are driver APIs expected to be exposed to the server
   * layer.  Note that the return type of `get` API is different from the
   * one defined in IDL.  This is because drivers (in core layer) should not
   * reply on the RPC data structures (defined in `kvs_types.hpp` in server
   * layer.)
   */

  void put(const std::string& key, int32_t value);
  int32_t get(const std::string& key) const;
  float get_average() const;
  void get_status(std::map<std::string, std::string>& status) const;

  /*
   * Following methods are driver APIs that are called by the framework
   * when `clear` / `save` / `load` RPC API is called.
   */

  void clear();
  void pack(jubatus::core::framework::packer& pk) const;
  void unpack(msgpack::object o);

 private:
  // Algorithm instance.
  jubatus::util::lang::shared_ptr<jubatus::core::kvs::kvs_algorithm> kvs_;
};

}  // namespace driver
}  // namespace core
}  // namespace jubatus

#endif  // KVS_DRIVER_HPP_
