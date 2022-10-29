#include <cxxopts.hpp>
#include <filesystem>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  auto img_path = std::string();

  auto options = cxxopts::Options("blur", "OpenCV blur");
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

  auto img_in = cv::imread(img_path, -1);
  if (img_in.empty()) {
    std::cerr << "Failed to open image" << std::endl;
    return -1;
  }

  auto img_out = cv::Mat();
  cv::GaussianBlur(img_in, img_out, cv::Size(5, 5), 3, 3);
  cv::GaussianBlur(img_out, img_out, cv::Size(5, 5), 3, 3);

  cv::namedWindow("blur-in", cv::WINDOW_NORMAL);
  cv::namedWindow("blur-out", cv::WINDOW_NORMAL);
  cv::imshow("blur-in", img_in);
  cv::imshow("blur-out", img_out);
  cv::waitKey(0);
  cv::destroyWindow("blur-in");
  cv::destroyWindow("blur-out");

  return 0;
}
