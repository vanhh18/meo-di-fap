#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

//tạo node 
node *makeNode(int data)
{
    // node *newNode = (node*)malloc(sizeof(node));
    node *newNode = new node();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

//chèn node
node* Insert(node *&root, int data)
{
    if(root == NULL)
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

//tìm node
bool Search(node *root, int data)
{
    if(root == NULL) return false;
    else if(root -> data == data) return true;
    else if(data <= root -> data) return Search(root -> left, data);
    else return Search(root -> right, data);
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
    while(root -> right == NULL)
    {
        root = root -> right;
    }
    return root;
}

node *Delete(node *&root, int data)
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
void traversal_inorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    traversal_inorder(root -> left);
    cout << root -> data << " ";
    traversal_inorder(root -> right);
}

//preorder: root -> left -> right
void traversal_preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root -> data << " ";
    traversal_preorder(root -> left);
    traversal_preorder(root -> right);
}
//postorder left -> right -> root
void traversal_postorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    traversal_postorder(root -> left); 
    traversal_postorder(root -> right);
    cout << root -> data << " ";
}
int main()
{
    node* root = NULL;
    cout << "inorder: ";
    traversal_inorder(root);
    cout << "\npreorder: ";
    traversal_preorder(root);
    cout << "\npostorder: ";
    traversal_postorder(root);
    return 0;
}