#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

typedef struct node
{
    string data;
    struct node *left;
    struct node *right;
    // Destructor to free memory
    ~node()
    {
        delete left;
        delete right;
    }
}node;

// Function to free the memory allocated for the tree
void FreeTree(node* root)
{
    delete root;
}

//Create a node 
node *makeNode(const string& data)
{
    // node *newNode = (node*)malloc(sizeof(node));
    node *newNode = new node();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

//Insert node
node* Insert(node *&root, const string& data)
{
    if(root == NULL) //empty tree
    {
        root = makeNode(data);
    }
    else if(data <= root -> data)
    {
        root -> left = Insert(root -> left, data);
    }
    else
    {
        root -> right = Insert(root -> right, data);
    }
    return root;
}

//Find node
bool Search(node *root, const string& data)
{
    if(root == NULL) return false;
    else if(root -> data == data) return true;
    else if(data <= root -> data) return Search(root -> left, data);
    else return Search(root -> right, data);
}

//Find height
int FindHeight(node *root)
{
    if(root == NULL)
        return -1;
    return max(FindHeight(root->left),FindHeight(root->right)) + 1;
}

node *FindMin(node *root)
{
    while(root -> left != NULL)
    {
        root = root -> left;
    }
    return root;
}

node *FindMax(node *root)
{
    while(root -> right != NULL)
    {
        root = root -> right;
    }
    return root;
}

//Delete node
node *Delete(node *&root, const string& data)
{
    if(root == NULL) return root;
    else if(data < root -> data) root -> left = Delete(root -> left, data);
    else if(data > root -> data) root -> right = Delete(root -> right, data);
    else if(data == root -> data)
    {
        //case1: no child
        if(root -> left == NULL && root -> right == NULL)
        {
            delete root;
            root = NULL;
        }
        //case2: 1 child
        else if(root -> left == NULL)
        {
            node *temp = root;
            root = root -> right;
            delete temp;
        }
        else if(root -> right == NULL)
        {
            node *temp = root;
            root = root -> left;
            delete temp;
        }
        //case3: 2 children
        else 
        {
            node *temp = FindMin(root -> right);
            root -> data = temp -> data;
            root -> right = Delete(root -> right, temp -> data);
        }
    }
    return root;
}

//inorder: left -> root -> right
void traversal_inorder(const node* root)
{
    if(root == NULL) return;
    traversal_inorder(root -> left);
    cout << root -> data << " ";
    traversal_inorder(root -> right);
}

//preorder: root -> left -> right
void traversal_preorder(const node* root)
{
    if(root == NULL) return;
    cout << root -> data << " ";
    traversal_preorder(root -> left);
    traversal_preorder(root -> right);
}
//postorder left -> right -> root
void traversal_postorder(const node* root)
{
    if(root == NULL) return;
    traversal_postorder(root -> left); 
    traversal_postorder(root -> right);
    cout << root -> data << " ";
}

void store_inorder(const node* root, vector<string>& sortedArray)
{
    if (root == NULL) return;
    store_inorder(root->left, sortedArray);
    sortedArray.push_back(root->data);
    store_inorder(root->right, sortedArray);
}

// Function to construct a balanced BST from a sorted array
node* BuildBalancedBST(const vector<string>& sortedArray, int start, int end)
{
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    node* newNode = makeNode(sortedArray[mid]);
    newNode->left = BuildBalancedBST(sortedArray, start, mid - 1);
    newNode->right = BuildBalancedBST(sortedArray, mid + 1, end);
    return newNode;
}

// Function to balance the binary search tree
node* BalanceTree(node* root)
{
    vector<string> sortedArray;
    store_inorder(root, sortedArray);
    return BuildBalancedBST(sortedArray, 0, sortedArray.size() - 1);
}

string binaryToATGC(const string& binaryString) {
    string atgcString;
    size_t length = binaryString.length();

    if (length % 8 != 0) {
        cerr << "Invalid binary string length. Length must be a multiple of 8." << endl;
        return atgcString;
    }

    for (size_t i = 0; i < length; i += 2) {
        string nucleotide;

        if (binaryString[i] == '0') {
            if (binaryString[i + 1] == '0') {
                nucleotide = "A";
            } else if (binaryString[i + 1] == '1') {
                nucleotide = "C";
            }
        } else if (binaryString[i] == '1') {
            if (binaryString[i + 1] == '0') {
                nucleotide = "G";
            } else if (binaryString[i + 1] == '1') {
                nucleotide = "T";
            }
        }

        if (!nucleotide.empty()) {
            atgcString += nucleotide;
        } else {
            cerr << "Invalid binary string. Only '0' and '1' characters are allowed." << endl;
            return "";
        }
    }

    return atgcString;
}

vector<string> convertToDNA(const string& binaryStrings) {
    vector<string> dnaString;

    size_t length = binaryStrings.length();
    size_t numStrings = length / 8;

    for (size_t i = 0; i < numStrings; ++i) {
        string binaryString = binaryStrings.substr(i * 8, 8);
        string atgcString = binaryToATGC(binaryString);
        dnaString.push_back(atgcString);
    }

    return dnaString;
}

int main()
{
    node* root = NULL;
    // Insert(root, "ATCG");
    // Insert(root, "CGTA");
    // Insert(root, "TACG");
    // Insert(root, "GCAT");
    // Insert(root, "GCTA");
    // Insert(root, "CATG");
    // Insert(root, "ACTG");
    // Insert(root, "ATGC");

    ifstream inputFile("Binary.txt");
    if (!inputFile) {
        cerr << "Failed to open the input file " << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        vector<string> dnaString = convertToDNA(line);

        for (const string& atgcString : dnaString) {
            Insert(root, atgcString);
        }
    }

    inputFile.close();
    cout << "Inorder traversal: ";
    traversal_inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    traversal_preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    traversal_postorder(root);
    cout << endl;

    string searchString;
    cout << "Enter a string to search: ";
    cin >> searchString;
    if (Search(root, searchString))
        cout << "String found!" << endl;
    else
        cout << "String not found!" << endl;

    cout << "Height of the tree: " << FindHeight(root) << endl;

    vector<string> sortedArray;
    store_inorder(root, sortedArray);
    root = BalanceTree(root);

    cout << "Inorder traversal after balancing the tree: ";
    traversal_inorder(root);
    cout << endl;

    cout << "Preorder traversal after balancing the tree: ";
    traversal_preorder(root);
    cout << endl;

    cout << "Postorder traversal after balancing the tree: ";
    traversal_postorder(root);
    cout << endl;
    cout << "Height of the tree: " << FindHeight(root) << endl;
    // Free memory
    FreeTree(root);

    return 0;
}