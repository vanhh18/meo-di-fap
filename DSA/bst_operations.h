#pragma once
#include "header.h"

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