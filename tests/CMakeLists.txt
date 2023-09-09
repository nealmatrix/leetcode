set(Boost_USE_SATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework)

enable_testing()

function(add_leetcode_test TEST_NAME TEST_SRC)
    add_executable(${TEST_NAME} ${TEST_SRC})
    target_link_libraries(${TEST_NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${LIB_NAME})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endfunction()

add_leetcode_test(test_1_two_sum test_1_two_sum.cpp)