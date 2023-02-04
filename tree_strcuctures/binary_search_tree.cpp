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
        Node *head;

        BinarySearchTree(){
            head = nullptr;
        }

        void insert(int val){
            Node* new_leaf = new Node(val);
            if(head == nullptr){
                head = new_leaf;
            }else{
                Node* focusNode = head;
                Node* parent;
                if(val >= focusNode->root){
                    focusNode = focusNode->right;
                    if(parent == nullptr){
                        parent->right = new_leaf;
                    }else{
                        return;
                    }
                }
            }
        }
};