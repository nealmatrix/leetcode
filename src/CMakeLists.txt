# file(GLOB_RECURSE LIB_SRC "two_sum/*.cpp")

add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE ${LIB_INCLUDE})