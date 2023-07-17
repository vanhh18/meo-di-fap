#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

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
// Make a new node.
node* makeNode(const string& data)
{
    node* newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to Insert Node in a Binary Search Tree.
node* Insert(node*& root, const string& data)
{   
    //Case 1: Tree is empty
    if (root == NULL)
    {
        root = makeNode(data);
    }
    //Case 2: Data want to insert is less than or equal to the data of the root.
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    //Case 3: Data want to insert is greater than the data of the root.
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

//To search an element in BST, returns true if element is found.
bool Search(const node* root, const string& data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

//To find height of the Binary Search Tree.
int FindHeight(const node* root)
{
    if (root == NULL)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

//Function to find minimum in a tree.
node* FindMin(node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

//Function to find maximum in a tree.
node* FindMax(node* root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// Function to delete a node from the tree.
node* Delete(node*& root, const string& data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else if (data == root->data)
    {
        // Case 1:  No child.
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //Case 2: One child.
        else if (root->left == NULL)
        {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        //Case 3: 2 children.
        else
        {
            node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

//Function to visit nodes in Inorder.
void traversal_inorder(const node* root)
{
    if (root == NULL) return;
    traversal_inorder(root->left);
    cout << root->data << " ";
    traversal_inorder(root->right);
}

//Function to visit nodes in Preorder.
void traversal_preorder(const node* root)
{
    if (root == NULL) return;
    cout << root->data << " ";
    traversal_preorder(root->left);
    traversal_preorder(root->right);
}

//Function to visit nodes in Postorder.
void traversal_postorder(const node* root)
{
    if (root == NULL) return;
    traversal_postorder(root->left);
    traversal_postorder(root->right);
    cout << root->data << " ";
}

//Store all the data in ascending order.
void store_inorder(const node* root, vector<string>& sortedArray)
{
    if (root == NULL) return;
    store_inorder(root->left, sortedArray);
    sortedArray.push_back(root->data);
    store_inorder(root->right, sortedArray);
}

//Take the middle as the root to build a balance tree.
node* BuildBalancedBST(const vector<string>& sortedArray, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    node* newNode = makeNode(sortedArray[mid]);
    newNode->left = BuildBalancedBST(sortedArray, start, mid - 1);
    newNode->right = BuildBalancedBST(sortedArray, mid + 1, end);
    return newNode;
}

//Function to balance a Binary Search Tree.
node* BalanceTree(node* root)
{
    vector<string> sortedArray;
    store_inorder(root, sortedArray);
    return BuildBalancedBST(sortedArray, 0, sortedArray.size() - 1);
}

//Function to convert the binary string to DNA string.
string binaryToATGC(const string& binaryString)
{
    string atgcString;
    size_t length = binaryString.length();

    if (length % 8 != 0)
    {
        cerr << "Invalid binary string length. Length must be a multiple of 8." << endl;
        return atgcString;
    }

    for (size_t i = 0; i < length; i += 2)
    {
        string nucleotide;

        if (binaryString[i] == '0')
        {
            if (binaryString[i + 1] == '0')
            {
                nucleotide = "A";
            }
            else if (binaryString[i + 1] == '1')
            {
                nucleotide = "C";
            }
        }
        else if (binaryString[i] == '1')
        {
            if (binaryString[i + 1] == '0')
            {
                nucleotide = "G";
            }
            else if (binaryString[i + 1] == '1')
            {
                nucleotide = "T";
            }
        }

        if (!nucleotide.empty())
        {
            atgcString += nucleotide;
        }
        else
        {
            cerr << "Invalid binary string. Only '0' and '1' characters are allowed." << endl;
            return "";
        }
    }

    return atgcString;
}

//Function to convert binary to DNA then store in a vector.
vector<string> convertToDNA(const string& binaryStrings)
{
    vector<string> dnaString;

    size_t length = binaryStrings.length();
    size_t numPixels = length / 8;

    for (size_t i = 0; i < numPixels; ++i)
    {   
        //Take a string of 8 characters each time.
        string binaryStr = binaryStrings.substr(i * 8, 8);
        //Then convert to DNA.
        string atgcString = binaryToATGC(binaryStr);
        //Store in a vector
        dnaString.push_back(atgcString);
    }
    return dnaString;
}

//Function to XOR 2 character of DNA.
string xorNucleotides(char nucleotide1, char nucleotide2)
{
    if (nucleotide1 == 'A')
    {   
        if (nucleotide2 == 'A')
            return "A";
        else if (nucleotide2 == 'T')
            return "T";
        else if (nucleotide2 == 'C')
            return "C";
        else if (nucleotide2 == 'G')
            return "G";
    }
    else if (nucleotide1 == 'T')
    {
        if (nucleotide2 == 'A')
            return "T";
        else if (nucleotide2 == 'T')
            return "A";
        else if (nucleotide2 == 'C')
            return "G";
        else if (nucleotide2 == 'G')
            return "C";
    }
    else if (nucleotide1 == 'C')
    {
        if (nucleotide2 == 'A')
            return "C";
        else if (nucleotide2 == 'T')
            return "G";
        else if (nucleotide2 == 'C')
            return "A";
        else if (nucleotide2 == 'G')
            return "T";
    }
    else if (nucleotide1 == 'G')
    {
        if (nucleotide2 == 'A')
            return "G";
        else if (nucleotide2 == 'T')
            return "C";
        else if (nucleotide2 == 'C')
            return "T";
        else if (nucleotide2 == 'G')
            return "A";
    }
}

//Function to XOR all the DNA in vector with a DNA sequence.
vector<string> xorDNASequences(const vector<string>& dnaString, const string& dnaSeq2)
{
    size_t numSequences = dnaString.size();
    size_t seqLength = dnaString[0].length();

    //Check length for XOR operation.
    if (seqLength != dnaSeq2.length())
    {
        cerr << "Error: DNA sequences must have the same length for XOR operation." << endl;
        return {};
    }

    //Initialize an empty vector with size of original DNA vector.
    vector<string> xorResults(numSequences);

    for (size_t i = 0; i < numSequences; ++i)
    {
        const string& sequence = dnaString[i];
        string xorResult;
        
        for (size_t j = 0; j < seqLength; ++j)
        {
            char nucleotide1 = sequence[j];
            char nucleotide2 = dnaSeq2[j];

            string xorNucleotide = xorNucleotides(nucleotide1, nucleotide2);

            xorResult += xorNucleotide;
        }

        xorResults[i] = xorResult;
    }

    return xorResults;
}

//Convert DNA vector to binary string.
string dnaToBinary(const vector<string>& dnaString)
{
    string linkedDNA;

    for (const string& dna : dnaString)
    {
        linkedDNA += dna;
    }

    string binaryString;

    for (const char& nucleotide : linkedDNA)
    {
        if (nucleotide == 'A')
            binaryString += "00";
        else if (nucleotide == 'C')
            binaryString += "01";
        else if (nucleotide == 'G')
            binaryString += "10";
        else if (nucleotide == 'T')
            binaryString += "11";
        else
        {
            cerr << "Invalid nucleotide: " << nucleotide << endl;
            return "";
        }
    }

    return binaryString;
}

string readBinaryStringFromFile(const string& filePath)
{
    string binaryString;

    ifstream inputFile(filePath);
    if (inputFile.is_open())
    {
        getline(inputFile, binaryString);
        inputFile.close();
        cout << "Binary string read from file: " << filePath << endl;
    }
    else
    {
        cerr << "Failed to open the input file: " << filePath << endl;
    }
    return binaryString;
}


int main()
{   
    
    // Mat image = imread("C:\\Users\\Lenovo\\Downloads\\358480551_523648293221376_324013621217729691_n.jpg", IMREAD_GRAYSCALE);

    // if (image.empty())
    // {
    //     cerr << "Unable to read the image." << endl;
    //     return 1;
    // }

    // string binaryString = convertImageToBinary(image);
    // // saveBinaryToTextFile(binaryString, "binary.txt");

    // // Determine the dimensions of the original image
    // int imageWidth = image.cols; // 125
    // int imageHeight = image.rows; // 113

    string binaryString = readBinaryStringFromFile("binary2.txt");

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

    string binaryString2 = dnaToBinary(xorResults);
    
    saveBinaryToTextFile(binaryString2, "binary2.txt");

    // Convert binary text back to image
    Mat restoredImage = convertTextToImage("binary2.txt", 125, 113);

    // Display the restored image
    imshow("Restored Image", restoredImage);
    waitKey(0);

    node* balancedTree = BalanceTree(root);
    
    delete balancedTree;

    return 0;
}