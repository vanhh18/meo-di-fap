#pragma once
#include "encrypted.h"
#include "header.h"

Mat restored(const Mat& image)
{
	string binaryString2 = convertImageToBinary(image);

	// Determine the dimensions of the original image
	int imageWidth = image.cols; // 125
	int imageHeight = image.rows; // 113

	saveBinaryToTextFile(binaryString2, "binary3.txt");

	vector<string> dnaString2 = convertToDNA(binaryString2);

	vector<string> xorResults2 = dnaString2;

	//xorResults = xorDNASequences(xorResults, "CGAT");

	xorResults2 = xorDNASequences(xorResults2, "TGAC");

	// xorResults = xorDNASequences(xorResults, "ATGC");

	// xorResults = xorDNASequences(xorResults, "TTTT");

	node* root = NULL;
	for (const string& result : xorResults2)
	{
		Insert(root, result);
	}

	string binaryString3 = dnaToBinary(xorResults2);

	saveBinaryToTextFile(binaryString3, "binary4.txt");

	// restored image
	Mat restoredImage = convertTextToImage("binary4.txt", imageWidth, imageHeight);

	// Display the restored image
	imshow("restored Image", restoredImage);
	waitKey(0);

	node* balancedTree = BalanceTree(root);

	delete balancedTree;

	return restoredImage;

}
