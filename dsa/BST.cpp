#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct node
{
    string data;
    struct node *left;
    struct node *right;
}node;

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

int main()
{
    node* root = NULL;
    Insert(root, "ATCG");
    Insert(root, "CGTA");
    Insert(root, "TACG");
    Insert(root, "GCAT");
    Insert(root, "GCTA");
    Insert(root, "CATG");
    Insert(root, "ACTG");
    Insert(root, "ATGC");

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

    return 0;
}