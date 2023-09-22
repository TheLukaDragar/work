project(work-modules)
cmake_minimum_required(VERSION 3.4)

# For C++17 on MacOS, we must set minimum target to 10.14+
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.14)

include(GNUInstallDirs)

set(NATIVE_HDRS
  
  "CommRustModule.h"
)

set(NATIVE_SRCS
  
  "CommRustModule.cpp"
)

add_library(work-modules-native
  ${NATIVE_HDRS}
  ${NATIVE_SRCS}
)

set_target_properties(work-modules-native PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(work-modules-native PRIVATE -Wc++17-extensions)

# reference local directory when building, use installation path when installing
target_include_directories(work-modules-native
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>

  # HACK
  PRIVATE
  "../../../../node_modules/react-native/ReactCommon/jsi"
  "../../../../node_modules/react-native/ReactCommon/react/nativemodule/core"
  "../../../../node_modules/react-native/ReactCommon/callinvoker"
  "../../../../node_modules/react-native/ReactCommon"
  "../../../native_rust_library"
)




