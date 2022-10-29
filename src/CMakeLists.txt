find_package(Threads REQUIRED)
add_library(cv STATIC cv/filter.cpp)
target_include_directories(cv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${OpenCV_INCLUDE_DIRS})
target_link_libraries(cv PRIVATE Threads::Threads ${OpenCV_LIBS})
set_target_properties(
  cv
  PROPERTIES CXX_STANDARD 20
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)
target_compile_options(cv PUBLIC -Wall -Wextra)
