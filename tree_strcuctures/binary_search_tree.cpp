#include <iostream>

struct Node{
    int root;
    Node *left;
    Node *right;
    Node(int val=0) :root(val), left(nullptr), right(nullptr){}
    Node(int val, Node *leftVal, Node *rightVal): root(val), left(leftVal), right(rightVal){}
};