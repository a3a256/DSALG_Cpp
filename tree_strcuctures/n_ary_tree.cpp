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


class NAryTree{
    public:
        Node* head;

        NAryTree(){
            head = nullptr;
        }


        void insert(int val){
            Node* new_leaf = new Node(val);
            if(head == nullptr){
                head = new_leaf;
            }else{
                if(head->root.size() < 2){
                    head->root.push_back(val);
                }else{
                    return;
                }
            }
        }
};