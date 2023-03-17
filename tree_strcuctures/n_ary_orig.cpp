#include <iostream>
#include <vector>


struct Node{
    int val;
    std::vector<Node*> children;

    Node(int val){
        this->val = val;
        this->children;
    }
};