#!/bin/bash -eu

script_dir=$(
    cd $(dirname $0)
    pwd
)
opencv_dir=$script_dir/opencv-4.x
contrib_dir=$script_dir/opencv_contrib-4.x
build_dir=$script_dir/build

wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
unzip opencv.zip
unzip opencv_contrib.zip

# Option reference: https://docs.opencv.org/4.x/db/d05/tutorial_config_reference.html
cmake -DWITH_CUDA=OFF -DBUILD_TESTS=OFF \
    -DIWTH_OPENMP=ON \
    -DOPENCV_EXTRA_MODULES_PATH=$contrib_dir/modules \
    -S $opencv_dir -B $build_dir
cmake --build $build_dir -- -j
