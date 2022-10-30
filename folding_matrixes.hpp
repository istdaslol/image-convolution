#ifndef folding_matrixes_h
#define folding_matrixes_h

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

char Sobel_vertical_data[] = {1,0,-1, 2,0,-2, 1,0,-1};
const cv::Mat Sobel_vertical(3,3, CV_8SC1, Sobel_vertical_data);

char Sobel_horizontal_data[] = {1,2,1, 0,0,0, -1,-2,-1};
const cv::Mat Sobel_horizontal(3,3, CV_8SC1, Sobel_horizontal_data);

#endif /* folding_matrixes_h */
