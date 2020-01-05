#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;

const cv::String keys =
    "{help h usage |      | print this message   }"
    "{@image1      |      | image1 for compare   }"
    "{@image2      |      | image2 for compare   }"
    ;

int main(int argc, char* argv[])
{
  cv::CommandLineParser parser(argc, argv, keys);
  parser.about("A Sample of CommandLineParser");

  if (parser.has("h"))
  {
    parser.printMessage();
    return 0;
  }

  cv::String img1 = parser.get<cv::String>(0);
  cv::String img2 = parser.get<cv::String>(1);

  if (!parser.check())
  {
    parser.printErrors();
    return 1;
  }

  auto src_im = cv::imread(img1, 0);
  auto dst_im = cv::imread(img2, 0);

  cv::Mat src_im_32f, dst_im_32f, hann;

  // src_im.convertTo(src_im_32f, CV_32F);
  // dst_im.convertTo(dst_im_32f, CV_32F);

  cv::Laplacian(src_im, src_im_32f, CV_32F);
  cv::Laplacian(dst_im, dst_im_32f, CV_32F);

  cv::Point2d shift = cv::phaseCorrelate(src_im_32f, dst_im_32f, hann);

  std::cout << shift.x << ", " << shift.y << std::endl;

  return 0;
}
