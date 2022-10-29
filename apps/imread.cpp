#include <opencv2/opencv.hpp>

#include <cxxopts.h>

int main(int argc, char** argv) {
    auto img = cv::imread(argv[1], -1);
    if (img.empty()) return -1;

    return 0;
}
