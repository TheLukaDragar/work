project(comm-tools)
cmake_minimum_required(VERSION 3.4)

include(GNUInstallDirs)

set(TOOLS_HDRS
  "Base64.h"
  "WorkerThread.h"
)

set(TOOLS_SRCS
  "Base64.cpp"
  "WorkerThread.cpp"
)

add_library(work-tools
  STATIC
  ${TOOLS_HDRS}
  ${TOOLS_SRCS}
)

target_link_libraries(work-tools
  Folly::folly
)

target_include_directories(coworkmm-tools
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
