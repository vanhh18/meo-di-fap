#pragma once

#include <string>
#include <vector>
#include <bitset>
#include <opencv2/core/types.hpp>
#include "opencv2/opencv.hpp"

std::string convertToBinary(const cv::Mat& image);
void saveBinaryStringToFile(const std::string& binaryString, const std::string& outputFilePath);
