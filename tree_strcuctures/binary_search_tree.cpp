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

        void inOrderTraversal(Node* currentNode){
            if(currentNode != nullptr){
                inOrderTraversal(currentNode->left);
                std::cout << currentNode->root << " ";
                inOrderTraversal(currentNode->right);
            }
        }
};


int main(){
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.inOrderTraversal(bst.head);
    return 0;
}