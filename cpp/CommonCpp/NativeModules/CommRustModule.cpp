#include "CommRustModule.h"
#include "InternalModules/RustPromiseManager.h"
#include "JSIRust.h"
#include "lib.rs.h"

#include <ReactCommon/TurboModuleUtils.h>

namespace work {

using namespace facebook::react;

CommRustModule::CommRustModule(std::shared_ptr<CallInvoker> jsInvoker)
    : CommRustModuleSchemaCxxSpecJSI(jsInvoker) {
}

jsi::Value CommRustModule::add(jsi::Runtime &rt, jsi::Number a, jsi::Number b) {
  return createPromiseAsJSIValue(
      rt, [this, a, b](jsi::Runtime &innerRt, std::shared_ptr<Promise> promise) {
        std::string error;
        try {
          auto currentID = RustPromiseManager::instance.addPromise(
              promise, this->jsInvoker_, innerRt);
          add(a.asNumber(), b.asNumber(), currentID);
        } catch (const std::exception &e) {
          error = e.what();
        };
      });
}


} // namespace work
