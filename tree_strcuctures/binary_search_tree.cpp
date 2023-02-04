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
                while(true){
                    parent = focusNode;
                    if(val >= focusNode->root){
                        focusNode = focusNode->right;
                        if(focusNode == nullptr){
                            parent->right = new_leaf;
                            return;
                        }
                    }else{
                        focusNode = focusNode->left;
                        if(focusNode == nullptr){
                            parent->left = new_leaf;
                            return;
                        }
                    }
                }
            }
        }
};