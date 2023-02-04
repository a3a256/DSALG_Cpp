#include <iostream>

struct Node{
    int root;
    struct Node *left;
    struct Node *right;

    Node(int root){
        this->root = root;
        this->left = nullptr;
        this->right = nullptr;
    }
};


class BinarySearchTree{

    public:
        Node *root;

        BinarySearchTree(){
            root = nullptr;
        }

        void insert(int val){
            Node* new_leaf = new Node(val);
            if(root == nullptr){
                root = new_leaf;
            }else{
                Node* itr = root;
                if(val >= itr->root){
                    if(itr->left == nullptr){
                        itr->left = new_leaf;
                    }else{
                        itr->left.insert(val);
                    }
                }
            }
        }
};