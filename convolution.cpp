#include "convolution.hpp"

using namespace cv;

char get_Convolution_at(const int x,const int y, const cv::Mat &srcImage, const cv::Mat &kernel, const int my_kernel_row, const int my_kernel_col)
{
    int row, col, nb_x, nb_y;
    char value = 0;
    
    for (row = 0; row < kernel.rows; row++)
    {
        for (col = 0; col < kernel.cols; col++)
        {
            // calculates the neighbours x coordinate and accounts for overflow
            nb_x = (row - my_kernel_row) + x;
            nb_x = nb_x > 0 ? nb_x : 0;
            nb_x = nb_x < srcImage.rows ? nb_x : srcImage.rows;
            
            // calculates the neighbours y coordinate and accounts for overflow
            nb_y = (col - my_kernel_col) + y;
            nb_y = nb_y > 0 ? nb_y : 0;
            nb_y = nb_y < srcImage.cols ? nb_y : srcImage.cols;
            
            value += srcImage.at<char>(nb_x,nb_y) * kernel.at<char>(row,col);
        }
    }
    return value;
}


char get_Convolution_at(const int x,const  int y, const Mat &srcImage, const Mat &kernel)
{
    return get_Convolution_at(x, y, srcImage, kernel, 1, 1);
}


void imageConvolution(const Mat &srcImage, Mat &destImage, const Mat &kernel)
{
    int x,y;
    for (x = 0; x < srcImage.rows; x++)
    {
        for (y = 0; y < srcImage.cols ; y++)
        {
            destImage.at<char>(x,y) = get_Convolution_at(x, y, srcImage, kernel);
        }
    }
}
