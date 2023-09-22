#pragma once

#include "../_generated/rustJSI.h"

#include <ReactCommon/TurboModuleUtils.h>
#include <jsi/jsi.h>
#include <memory>

namespace work
{

  namespace jsi = facebook::jsi;

  class CommRustModule : public facebook::react::CommRustModuleSchemaCxxSpecJSI
  {
    virtual jsi::Value add(
        jsi::Runtime &rt,
        jsi::Number a,
        jsi::Number b) override;

  public:
    CommRustModule(std::shared_ptr<facebook::react::CallInvoker> jsInvoker);
  };

} // namespace work
