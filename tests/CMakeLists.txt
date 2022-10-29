add_executable(test_filter test_filter.cpp)
target_link_libraries(test_filter PRIVATE cv gtest gtest_main)
set_target_properties(
  test_filter
  PROPERTIES CXX_STANDARD 20
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)
gtest_discover_tests(test_filter)
