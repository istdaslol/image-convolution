#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <algorithm>

#include "convolution.hpp"
#include "folding_matrixes.hpp"

#define ARG_FILE_OUT "-f"
#define ARG_PRESENT_RESULT "-s"
#define ARG_HELP "-h"

/**
 * Checkes if a given argument is within the argv
 * @param begin start of the argv
 * @param end end of the argv
 * @param option arguemt to be checked for existence
 * @return True if argument was found False otherwise
 */
bool arg_option_exists(const char** begin, const char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

/**
 * Prints the help message
 */
void print_help(void)
{
    std::cout << "[command] <filename> >arguments<" << std::endl;
    std::cout << ARG_HELP << " prints this message" << std::endl;
    std::cout << ARG_PRESENT_RESULT << " presents the results in a new window" << std::endl;
    std::cout << ARG_FILE_OUT << " saves the results as a file" << std::endl;
    std::cout << "arguments have to be listed separated: -sf is not valid" << std::endl;
    std::cout << "per default none is selected so at least one is needed" << std::endl;
}


int main(int argc, const char * argv[])
{
    // if not enough arguments or help are passed: print help
    if (argc < 3 || arg_option_exists(argv, argv + argc, ARG_HELP))
    {
        print_help();
        exit(EXIT_FAILURE);
    }
    
    cv::Mat srcImage = cv::imread(argv[1], 0);
    
    if (srcImage.empty())
    {
        exit(EXIT_FAILURE);
    }
    
    std::string srcImage_Name = argv[1];
    
    cv::Mat destImage_vert(srcImage.rows, srcImage.cols, CV_8SC1);
    cv::Mat destImage_hori(srcImage.rows, srcImage.cols, CV_8SC1);
    cv::Mat destImage_sum(srcImage.rows, srcImage.cols, CV_8SC1);
    
    imageConvolution(srcImage, destImage_vert, Sobel_vertical);
    imageConvolution(srcImage, destImage_hori, Sobel_horizontal);
    
    cv::addWeighted(destImage_vert, 1, destImage_hori, 1, 0, destImage_sum);
    
    /**
     * If the option for file output is passed
     */
    if (arg_option_exists(argv, argv + argc, ARG_FILE_OUT))
    {
        cv::imwrite(srcImage_Name + " Convoluted Image Vertical.png", destImage_vert);
        cv::imwrite(srcImage_Name + " Convoluted Image Horizontal.png", destImage_hori);
        cv::imwrite(srcImage_Name + " Convoluted Image Sum.png", destImage_sum);
    }

    /**
     * If the option for presenting the result
     */
    if (arg_option_exists(argv, argv + argc, ARG_PRESENT_RESULT))
    {
        cv::imshow("Original Image", srcImage);
        cv::imshow("Convoluted Image Vertical", destImage_vert);
        cv::imshow("Convoluted Image Horizontal", destImage_hori);
        cv::imshow("Convoluted Image Sum", destImage_sum);
        cv::waitKey(0);
    }

    return EXIT_SUCCESS;
}
