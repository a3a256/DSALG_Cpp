#include <iostream>

struct Node{
    int data;
    Node *next;

    Node(int val=0) :data(val), next(nullptr){}

    Node(int val, Node *tempNext):data(val), next(tempNext){}
};


class LinkedList{
    Node *head;
    public:

        LinkedList():head(nullptr)
        {
        }

        void insert(int val){
            Node* new_node = new Node(val);

            if (head == nullptr){
                head = new_node;
            }else{
                head = head->next;
                head = new_node;
            }
        }
};