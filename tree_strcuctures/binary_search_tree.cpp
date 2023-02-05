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

        void preOrderTraversal(Node* currentNode){
            if(currentNode != nullptr){
                std::cout << currentNode->root << " ";
                preOrderTraversal(currentNode->left);
                preOrderTraversal(currentNode->right);
            }
        }

        void postOrderTraversal(Node* currentNode){
            if(currentNode != nullptr){
                postOrderTraversal(currentNode->left);
                postOrderTraversal(currentNode->right);
                std::cout << currentNode->root << " ";
            }
        }
};


int main(){
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(1);
    bst.insert(4);
    bst.insert(7);
    bst.inOrderTraversal(bst.head);
    std::cout << std::endl;
    bst.preOrderTraversal(bst.head);
    std::cout << std::endl;
    bst.postOrderTraversal(bst.head);
    return 0;
}