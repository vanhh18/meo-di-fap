#include "bst_operations.h"
#include <iostream>
#include <algorithm>

node::~node()
{
    // Implementation of destructor
}

node* makeNode(const std::string& data)
{
    // Implementation of makeNode function
}

node* Insert(node*& root, const std::string& data)
{
    // Implementation of Insert function
}

bool Search(node* root, const std::string& data)
{
    // Implementation of Search function
}

int FindHeight(node* root)
{
    // Implementation of FindHeight function
}

node* FindMin(node* root)
{
    // Implementation of FindMin function
}

node* FindMax(node* root)
{
    // Implementation of FindMax function
}

node* Delete(node*& root, const std::string& data)
{
    // Implementation of Delete function
}

void traversal_inorder(const node* root)
{
    // Implementation of traversal_inorder function
}

void traversal_preorder(const node* root)
{
    // Implementation of traversal_preorder function
}

void traversal_postorder(const node* root)
{
    // Implementation of traversal_postorder function
}

void store_inorder(const node* root, std::vector<std::string>& sortedArray)
{
    // Implementation of store_inorder function
}

node* BuildBalancedBST(const std::vector<std::string>& sortedArray, int start, int end)
{
    // Implementation of BuildBalancedBST function
}

node* BalanceTree(node* root)
{
    // Implementation of BalanceTree function
}
