#include "header.h"
#include "binary_converter.h"
#include "dna_operations.h"
#include "bst_operations.h"


int main()
{

    Mat image = imread("C:\\Users\\DGC\\Desktop\\startOpencv1\\anh2.jpg", IMREAD_GRAYSCALE);

    if (image.empty())
    {
        cerr << "Unable to read the image." << endl;
        return 1;
    }

    string binaryString = convertImageToBinary(image);
    saveBinaryToTextFile(binaryString, "binary.txt");

    // Determine the dimensions of the original image
    int imageWidth = image.cols; // 125
    int imageHeight = image.rows; // 113

    string binaryString1 = readBinaryStringFromFile("binary2.txt");

    vector<string> dnaString = convertToDNA(binaryString);

    vector<string> xorResults = dnaString;

    xorResults = xorDNASequences(xorResults, "ATGC");

    xorResults = xorDNASequences(xorResults, "TTTT");

    // xorResults = xorDNASequences(xorResults, "ATGC");

    // xorResults = xorDNASequences(xorResults, "TTTT");

    node* root = NULL;
    for (const string& result : xorResults)
    {
        Insert(root, result);
    }

    string binaryStringg = dnaToBinary(xorResults);

    saveBinaryToTextFile(binaryString, "binary2.txt");

    // Convert binary text back to image
    Mat restoredImage = convertTextToImage("binary2.txt", imageWidth, imageHeight);

    // Display the restored image
    imshow("Restored Image", restoredImage);
    waitKey(0);

    node* balancedTree = BalanceTree(root);

    delete balancedTree;

    return 0;
}