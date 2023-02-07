#include <iostream>
#include <vector>


struct Node{
    std::vector<int> root;
    struct Node* left;
    struct Node* right;

    Node(int val){
        this->root.push_back(val);
        this->left = nullptr;
        this->right = nullptr;
    }
};