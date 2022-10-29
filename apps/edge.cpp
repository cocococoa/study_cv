#include <cxxopts.hpp>
#include <filesystem>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  auto img_path = std::string();

  auto options = cxxopts::Options("edge", "OpenCV edge");
  options.add_options()
      // help
      ("h,help", "Print help")
      // input path
      ("i", "Input path", cxxopts::value<std::string>(img_path));
  const auto result = options.parse(argc, argv);
  if (argc == 1 || result.count("help") >= 1) {
    std::cerr << options.help({""});
    return -1;
  }
  if (!std::filesystem::exists(std::filesystem::status(img_path))) {
    std::cerr << "No such file: " << img_path << std::endl;
    return -1;
  }

  auto img_rgb = cv::imread(img_path, -1);
  if (img_rgb.empty()) {
    std::cerr << "Failed to open image" << std::endl;
    return -1;
  }

  auto img_gray = cv::Mat();
  auto img_cny = cv::Mat();
  cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
  cv::Canny(img_gray, img_cny, 10, 100, 3, true);

  cv::namedWindow("edge-rgb", cv::WINDOW_NORMAL);
  cv::namedWindow("edge-gray", cv::WINDOW_NORMAL);
  cv::namedWindow("edge-cny", cv::WINDOW_NORMAL);
  cv::imshow("edge-rgb", img_rgb);
  cv::imshow("edge-gray", img_gray);
  cv::imshow("edge-cny", img_cny);
  cv::waitKey(0);
  cv::destroyWindow("edge-rgb");
  cv::destroyWindow("edge-gray");
  cv::destroyWindow("edge-cny");

  return 0;
}
