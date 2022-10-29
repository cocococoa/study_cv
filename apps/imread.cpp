#include <cxxopts.hpp>
#include <filesystem>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv) {
  auto img_path = std::string();

  auto options = cxxopts::Options("imread", "OpenCV imread");
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

  auto img = cv::imread(img_path, -1);
  if (img.empty()) {
    std::cerr << "Failed to open image" << std::endl;
    return -1;
  }

  cv::namedWindow("imread", cv::WINDOW_NORMAL);
  cv::imshow("imread", img);
  cv::waitKey(0);
  cv::destroyWindow("imread");

  return 0;
}
