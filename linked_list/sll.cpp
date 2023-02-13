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

        void insert_at_end(int val){
            Node* new_node = new Node(val);
            Node* itr = head;
            while(itr->next != nullptr){
                itr = itr->next;
            }
            itr->next = new_node;
        }

        int get_length(){
            Node* itr = head;
            int count = 0;
            while(itr != nullptr){
                itr = itr->next;
                count ++;
            }

            return count;
        }

        void delete_at(int index){
            int length = get_length();
            if(index >= length){
                std::cout << "Out of range\n";
            }else{
                Node* itr = head;
                int i = 0;
                while(itr != nullptr){
                    if(i == index-1){
                        itr->next = itr->next->next;
                        break;
                    }
                    i ++;
                    itr = itr->next;
                }
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

        void bubbleSort(){
            Node* itr;
            bool sorted = false;
            int temp;
            while(!(sorted)){
                sorted = true;
                itr = head;
                while(itr->next != nullptr){
                    if(itr->data > itr->next->data){
                        sorted = false;
                        temp = itr->data;
                        itr->data = itr->next->data;
                        itr->next->data = temp;
                    }
                    itr = itr->next;
                }
            }
        }


        int search(int start, int end, int target){
            int l = (start+end)/2;
            Node* itr = head;
            while(start<l){
                itr = itr->next;
                start ++;
            }

            if (itr->data == target){
                return l;
            }else if(target > itr->data){
                return search(l+1, end, target);
            }else if(target < itr->data){
                return search(start, l-1, target);
            }


            return -1;
        }
};


int main(){
    LinkedList lst;
    lst.insert(1);
    lst.insert(2);
    lst.insert(3);

    lst.display();

    lst.insert_at_end(5);

    lst.insert_at_end(4);
    lst.insert(8);

    lst.display();

    lst.bubbleSort();

    lst.display();

    lst.delete_at(2);

    lst.display();

    std::cout << lst.search(0, lst.get_length(), 4);
}