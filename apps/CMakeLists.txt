foreach(exe filter imread)
  add_executable(${exe} ${exe}.cpp)
  target_include_directories(${exe} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
  target_link_libraries(${exe} PRIVATE cv cxxopts::cxxopts)
  set_target_properties(
    ${exe}
    PROPERTIES CXX_STANDARD 20
               CXX_STANDARD_REQUIRED ON
               CXX_EXTENSIONS OFF)
endforeach()
