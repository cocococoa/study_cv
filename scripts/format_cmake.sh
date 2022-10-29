#!/bin/bash -eu

script_dir=$(
    cd $(dirname $0)
    pwd
)
base_dir=$script_dir/..

file_list=(
    CMakeLists.txt
    cmake/deps.cmake
    apps/CMakeLists.txt
    src/CMakeLists.txt
    tests/CMakeLists.txt
)

files=""
for file in "${file_list[@]}"; do
    files+=" $base_dir/$file"
    cmake-format -i -l debug --line-width 120 --tab-size 4 $base_dir/$file
done

cmake-lint --line-width 120 --tab-size 4 $files
