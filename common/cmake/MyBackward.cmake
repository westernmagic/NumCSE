set (Backward_DIR ${PROJECT_ROOT_DIR}/external/backward-cpp)
find_package (Backward REQUIRED NO_MODULE)

set_property (TARGET Backward::Backward PROPERTY INTERFACE_SOURCES ${Backward_DIR}/backward.cpp)

