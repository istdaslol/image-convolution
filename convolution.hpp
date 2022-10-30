#ifndef convolution_hpp
#define convolution_hpp

#include <opencv2/core/core.hpp>

/**
 * calculates the convolution value with a given kernel of rectangular shape
 * @param x coordinate on the row
 * @param y coordinate on the coloum
 * @param srcImage image to calculate value from
 * @param kernel kernal to use for vlaue calculation
 * @param my_kernel_row x position of the target pixel within the kernel
 * @param my_kernel_col y position of the target pixel within the kernel
 * @return convuluted pixel value
 */
char get_Convolution_at(const int x,const int y, const cv::Mat &srcImage, const cv::Mat &kernel, const int my_kernel_row, const int my_kernel_col);

/**
 * calculats the convolution value with a 3x3 kernel
 * @param x coordinate on the row
 * @param y coordinate on the coloum
 * @param srcImage image to calculate value from
 * @param kernel kernal to use for vlaue calculation
 * @return convuluted pixel value
 */
char get_Convolution_at(const int x,const int y, const cv::Mat &srcImage, const cv::Mat &kernel);

/**
 * @param srcImage adrdess to source image
 * @param destImage address to destination image
 * @param kernel address to the kernel used
 */
void imageConvolution(const cv::Mat &srcImage, cv::Mat &destImage, const cv::Mat &kernel);

#endif /* convolution_hpp */
