#include <iostream>
#include <vector>
#include <math.h>

int calculate(std::vector<int> arr){
    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += pow(arr.at(i), 2);
    }

    return sqrt(sum);
}


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


class NAryTree{
    public:
        Node* head;

        NAryTree(){
            head = nullptr;
        }


        void insert(int val){
            Node* new_leaf = new Node(val);
            int value;
            if(head == nullptr){
                head = new_leaf;
            }else{
                if(head->root.size() < 2){
                    head->root.push_back(val);
                }else{
                    value = calculate(head->root);
                    if(val >= value/2){
                        Node* focusNode = head;
                        Node* parent;
                        while(true){
                            parent = focusNode;
                            if(val >= calculate(focusNode->root)){
                                focusNode = focusNode->right;
                                if(focusNode == nullptr){
                                    std::cout << "right\n";
                                    parent->right = new_leaf;
                                    return;
                                }
                            }else{
                                focusNode = focusNode->left;
                                if(focusNode == nullptr){
                                    std::cout << "left\n";
                                    parent->left = new_leaf;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }


        void inOrderTraversal(Node* currentNode){
            if(currentNode != nullptr){
                inOrderTraversal(currentNode->left);
                for(int i = 0; i<currentNode->root.size(); i++){
                    std::cout << currentNode->root[i] << ",";
                }
                std::cout << " ";

                inOrderTraversal(currentNode->right);
            }
        }


        void preOrderTraversal(Node* currentNode){
            if(currentNode != nullptr){

                for(int i = 0; i<currentNode->root.size(); i++){
                    std::cout << currentNode->root[i] << ",";
                }
                std::cout << " ";
                preOrderTraversal(currentNode->left);

                preOrderTraversal(currentNode->right);
            }
        }


        void postOrderTraversal(Node* currentNode){
            if(currentNode != nullptr){
                postOrderTraversal(currentNode->left);

                postOrderTraversal(currentNode->right);

                for(int i = 0; i<currentNode->root.size(); i++){
                    std::cout << currentNode->root[i] << ",";
                }
                std::cout << " ";
            }
        }


        int height(Node* currentNode){
            if(currentNode == nullptr){
                return 0;
            }else{
                int tree_left;
                int tree_right;
                tree_left = height(currentNode->left);
                tree_right = height(currentNode->right);
                if(tree_left > tree_right){
                    return tree_left + 1;
                }else{
                    return tree_right + 1;
                }
            }
        }
};



int main(){
    NAryTree tree;

    tree.insert(1);
    tree.insert(4);

    tree.insert(5);
    tree.insert(7);

    tree.insert(2);

    tree.inOrderTraversal(tree.head);

    std::cout << "\n";

    tree.preOrderTraversal(tree.head);

    std::cout << "\n";

    tree.postOrderTraversal(tree.head);

    std::cout << "\n";

    std::cout << tree.height(tree.head);
}