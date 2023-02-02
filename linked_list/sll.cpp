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
            Node* itr = head;
            if (itr == nullptr){
                head = new_node;
            }else{
                new_node->next = head;
                head = new_node;
            }
        }

        void display(){
            Node* temp = head;
            while(temp != nullptr){
                std::cout << temp->data << "-->";
                temp = temp->next;
            }
            std::cout << "null, so far\n";
        }
};


int main(){
    LinkedList lst;
    lst.insert(1);
    lst.insert(2);
    lst.insert(3);

    lst.display();
}