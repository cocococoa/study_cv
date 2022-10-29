if(LCV_BUILD_CXXOPTS)
    include(FetchContent)
    FetchContent_Declare(cxxopts GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git)
    FetchContent_MakeAvailable(cxxopts)
else()
    find_package(cxxopts REQUIRED)
endif()

if(LCV_BUILD_GTEST)
    include(FetchContent)
    FetchContent_Declare(googletest # Specify the commit you depend on and update it regularly.
                         URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip)
    set(gtest_force_shared_crt
        ON
        CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    include(GoogleTest)
else()
    find_package(GTest REQUIRED)
    add_library(gtest ALIAS GTest::gtest)
    add_library(gtest_main ALIAS GTest::gtest_main)
endif()

find_package(OpenCV REQUIRED)
