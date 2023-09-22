project(work-common-cpp)

# 3.13+ required for CMP0079 to be set
cmake_minimum_required(VERSION 3.13)

include(GNUInstallDirs)


add_subdirectory(NativeModules)
add_subdirectory(Tools)



target_link_libraries(work-modules-native
work-tools
)

