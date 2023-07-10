#pragma once

#include <string>
#include <vector>

typedef struct node
{
    std::string data;
    struct node* left;
    struct node* right;

    ~node();
} node;

node* makeNode(const std::string& data);
node* Insert(node*& root, const std::string& data);
bool Search(node* root, const std::string& data);
int FindHeight(node* root);
node* FindMin(node* root);
node* FindMax(node* root);
node* Delete(node*& root, const std::string& data);
void traversal_inorder(const node* root);
void traversal_preorder(const node* root);
void traversal_postorder(const node* root);
void store_inorder(const node* root, std::vector<std::string>& sortedArray);
node* BuildBalancedBST(const std::vector<std::string>& sortedArray, int start, int end);
node* BalanceTree(node* root);
