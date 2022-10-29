#include <cxxopts.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  auto options = cxxopts::Options("imread", "OpenCV imread");
  auto img_path = std::string();
  options.add_options()
      // help
      ("h,help", "Print help")
      // input path
      ("i", "Input path", cxxopts::value<std::string>(img_path));
  const auto result = options.parse(argc, argv);
  if (argc == 1 || result.count("help") >= 1) {
    std::cout << options.help({""});
    return -1;
  }

  auto img = cv::imread(img_path, -1);
  if (img.empty()) return -1;

  return 0;
}
