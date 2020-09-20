#include <iostream>

#include <opencv4/opencv2/opencv.hpp>
int main() {
    std::cout << "Hello, World!" << std::endl;
    cv::namedWindow("1");
    cv::Mat img = cv::imread("/home/lyp/1_Code/test_opengl/spongebob.jpg", 1);
    cv::imshow("spongbob", img);
    cv::waitKey(0);
    return 0;
}