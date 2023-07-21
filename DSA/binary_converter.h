#pragma once
#include "header.h"


//Definition of Node for Binary search tree.
struct node
{
    string data;
    node* left;
    node* right;

    //Deconstructor.
    ~node()
    {
        delete left;
        delete right;
    }
};

//Function to convert the image to binary string.
string convertImageToBinary(const Mat& image)
{
    string binaryString;
    for (int i = 0; i < image.rows; ++i)
    {
        for (int j = 0; j < image.cols; ++j)
        {
            uchar pixelValue = image.at<uchar>(i, j);
            string binaryValue = bitset<8>(pixelValue).to_string();
            binaryString += binaryValue;
        }
    }
    return binaryString;
}

//Function to save the binary string to a text file.
void saveBinaryToTextFile(const string& binaryString, const string& outputFilePath)
{
    ofstream outputFile(outputFilePath);
    if (outputFile.is_open())
    {
        outputFile << binaryString;
        outputFile.close();
        cout << "Binary string saved to " << outputFilePath << endl;
    }
    else
    {
        cerr << "Unable to open the output file." << endl;
    }
}

//Function to convert binary string from text file to image.
Mat convertTextToImage(const string& filename, int imageWidth, int imageHeight)
{
    Mat restoredImage(imageHeight, imageWidth, CV_8UC1);

    ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cout << "Failed to open the input file." << endl;
        return restoredImage;
    }

    string restoredBinaryText;
    getline(inputFile, restoredBinaryText);
    inputFile.close();

    int index = 0;
    cv::MatIterator_<uchar> it, end;
    for (it = restoredImage.begin<uchar>(), end = restoredImage.end<uchar>(); it != end; ++it)
    {
        bitset<8> bits(restoredBinaryText.substr(index, 8));
        *it = static_cast<uchar>(bits.to_ulong());
        index += 8;
    }

    return restoredImage;
}