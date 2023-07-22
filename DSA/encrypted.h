#pragma once
#include "header.h"
#include "binary_converter.h"
#include "dna_operations.h"
#include "bst_operations.h"

Mat encrypted(const Mat& image)
{
    string binaryString = convertImageToBinary(image);
    saveBinaryToTextFile(binaryString, "binary1.txt");

    // Determine the dimensions of the original image
    int imageWidth = image.cols; // 125
    int imageHeight = image.rows; // 113

    string binaryString1 = readBinaryStringFromFile("binary1.txt");

    vector<string> dnaString1 = convertToDNA(binaryString1);

    vector<string> xorResults1 = dnaString1;


    string binaryString2 = dnaToBinary(xorResults1);

    //xorResults = xorDNASequences(xorResults, "CGAT");

    xorResults1 = xorDNASequences(xorResults1, "TGAC");

    // xorResults = xorDNASequences(xorResults, "ATGC");

    // xorResults = xorDNASequences(xorResults, "TTTT");

    node* root = NULL;
    for (const string& result : xorResults1)
    {
        Insert(root, result);
    }

    string binaryString3 = dnaToBinary(xorResults1);

    saveBinaryToTextFile(binaryString3, "binary2.txt");

    // encrypted image
    Mat encryptedImage = convertTextToImage("binary2.txt", imageWidth, imageHeight);

    // Display the encrypted image
    imshow("Encrypted Image", encryptedImage);
    waitKey(0);

    imwrite("encrypted.png", encryptedImage);

    node* balancedTree = BalanceTree(root);

    delete balancedTree;

    return encryptedImage;
}

