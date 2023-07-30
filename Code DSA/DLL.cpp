#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *next,*prev;
};
struct DLL{
    struct Node*head;
    struct Node*tail;
};