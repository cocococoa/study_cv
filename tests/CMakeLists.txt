enable_testing()
add_executable(test_filter test_filter.cpp)
target_link_libraries(test_filter PRIVATE cv gtest_main)
gtest_discover_tests(test_filter)
