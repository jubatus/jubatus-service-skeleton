// This file is modified based on the jenerated template file

#include "kvs_serv.hpp"

#include <utility>

// Use mixer to support distributed mode.
#include <jubatus/server/framework/mixer/mixer_factory.hpp>

// Use logger provided by framework.
#include <jubatus/server/common/logger/logger.hpp>

namespace jubatus {
namespace server {

namespace {

/**
 * This struct defines the format of the server configuration given in JSON.
 *
 * In this example, these parameters are dummy - actually not used for
 * calculation.  It is written to show you how to handle config.  Also see
 * `set_config` method below.
 */
struct kvs_serv_config {
  int param1;
  std::string param2;

  template <typename Ar>
  void serialize(Ar& ar) {
    ar
        & JUBA_MEMBER(param1)
        & JUBA_MEMBER(param2);
  }
};
}

/**
 * Constructor.  Do your initialization work here.  Note that the server
 * configuration (JSON) is not yet available.
 */
kvs_serv::kvs_serv(
  const jubatus::server::framework::server_argv& a,
  const jubatus::util::lang::shared_ptr<jubatus::server::common::lock_service>& zk)
    : jubatus::server::framework::server_base(a),
      // Create a driver, which is an external API of "core" layer.
      driver_(new jubatus::core::driver::kvs_driver()),
      // Create a mixer instance.
      mixer_(jubatus::server::framework::mixer::create_mixer(
          a, zk, rw_mutex(), user_data_version())) {
  mixer_->set_driver(driver_.get());
}

/**
 * Destructor.  In most cases you don't need to implement this.
 */
kvs_serv::~kvs_serv() {
}

/**
 * This is an idiom; just return the mixer instance you created in the
 * constructor.  Should not return NULL; standalone mode will work even
 * if you do so, though.
 */
jubatus::server::framework::mixer::mixer* kvs_serv::get_mixer() const {
  return mixer_.get();
}

/**
 * This is an idiom; just return the driver instance you created in the
 * constructor.  Should not return NULL; if you do so, some common API calls
 * (`save`, `load`, `clear`, etc.) will not work.
 */
jubatus::core::driver::driver_base* kvs_serv::get_driver() const {
  return driver_.get();
}

/**
 * This method will be invoked when `get_config` RPC API is called.
 * This method is expected to return the configuration string that was passed
 * via `set_config` API.
 */
std::string kvs_serv::get_config() const {
  return config_;
}

/**
 * This method is expected to return the version number of the data structure.
 * When `load` RPC is called, the framework automatically validates if the
 * user_data_version of the model file is equal to the user_data_version of
 * the running server instance to avoid loading incompatibile models.  You
 * need to manually increment the number by hand everytime after changing the
 * structure of serialized models.
 */
uint64_t kvs_serv::user_data_version() const {
  return 1u;
}

/**
 * This method will be invoked by the framework when `get_status` RPC API is
 * called.  You can return additional service-specific metircs (e.g., number
 * of labels in Classifier), by modifying `status` (string-to-string map.)
 */
void kvs_serv::get_status(status_t& status) const {
  /*
   * Actual status values are added by the driver.
   */
  driver_->get_status(status);
}

/**
 * This method will be invoked when the configuration file was successfully
 * loaded.  You need to store the config string in somewhere - you'll need it
 * when implementing `get_config` method.  You can safely assume that all RPC
 * calls will be called after `set_config` call.
 */
void kvs_serv::set_config(const std::string& config) {
  /*
   * Using `jsonconfig` module, which is a JSON/struct mapping mechanism
   * provided by the framework, convert the raw JSON string into
   * `struct kvs_serv_config`.  The struct to be converted must implement
   * `serialize` method (see definition above.)
   */
  core::common::jsonconfig::config config_root(
      jubatus::util::lang::lexical_cast<jubatus::util::text::json::json>(config));
  kvs_serv_config conf =
    core::common::jsonconfig::config_cast_check<kvs_serv_config>(config_root);

  /*
   * Keep the config.
   */
  config_ = config;

  /*
   * You can now use the config values.  When implementing machine learning
   * algorithms, these values can be used to pass in hyper parameters.  In that
   * case you'll need to instantiate a driver layer here, instead of the
   * constructor.
   *
   * In this example, we actually don't use parameters; this code is just to
   * show you how to use config values and to print logs.
   */
  LOG(INFO) << "param1 = " << conf.param1;
  LOG(INFO) << "param2 = " << conf.param2;
}

/**
 * This method will be invoked when `put` RPC API is called.
 */
bool kvs_serv::put(const std::string& key, int32_t value) {
  driver_->put(key, value);
  return true;
}

/**
 * This method will be invoked when `get` RPC API is called.
 */
entry kvs_serv::get(const std::string& key) const {
  /*
   * Get a result from driver.
   */
  int32_t v = driver_->get(key);

  /*
   * Pack the result into RPC data structure.
   */
  entry result;
  result.key = key;
  result.value = v;

  /*
   * Return the result.
   */
  return result;
}

/**
 * This method will be invoked when `get_average` RPC API is called.
 */
float kvs_serv::get_average() const {
  return driver_->get_average();
}

}  // namespace server
}  // namespace jubatus
