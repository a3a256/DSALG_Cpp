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
                            if(val >= calculate(focusNode->root)/2 && focusNode->root.size() == 2){
                                focusNode = focusNode->right;
                            }
                        }
                    }
                }
            }
        }
};