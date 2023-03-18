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


class NTree{
    Node* head;

    NTree(){
        head = nullptr;
    }

    void insert(int val){
        Node* new_leaf = new Node(val);
        if(head == nullptr){
            head = new_leaf;
            return;
        }

        std::string level, arr;
        Node* focusNode = head;
        Node* parent;
        if(focusNode->children.size() == 0){
            focusNode->children.push_back(new_leaf);
        }else{
            focusNode = head;
            while(true){
                parent = focusNode;
                std::cout << "Do you want to continue with the current level?";
                std::cin >> level;
                if(level == "y"){
                    focusNode->children.push_back(new_leaf);
                    return;
                }else{
                    for(int i = 0; i<focusNode->children.size(); i++){
                        std::cout << "Do you want to continue at " << focusNode->children[i]->val << "?";
                        std::cin >> level;
                        if(level == "y"){
                            focusNode = focusNode->children[i];
                            if(focusNode->children.size() == 0){
                                focusNode->children.push_back(new_leaf);
                            }
                        }
                    }
                }
            }
        }
    }
};