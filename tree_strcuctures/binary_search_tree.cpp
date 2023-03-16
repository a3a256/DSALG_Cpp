#include <iostream>
#include <vector>

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

        void currentLevel(Node* node, int level){
            if(node == nullptr){
                return;
            }
            if(level == 1){
                std::cout << node->root << " ";
            }else if(level > 1){
                currentLevel(node->left, level-1);
                currentLevel(node->right, level-1);
            }
        }

        void levelOrderTraversal(Node* currentNode){
            int h = height(currentNode);
            for(int i = 1; i<=h; i++){
                currentLevel(currentNode, i);
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

        std::vector<int> iot(Node* currentNode){
            std::vector<Node*> queue;
            std::vector<int> res;
            Node* tempNode;
            queue.push_back(currentNode);
            int n;
            while(queue.size() != 0){
                n = queue.size();
                while(n > 0){
                    tempNode = queue.at(0);
                    queue.erase(queue.begin());
                    res.push_back(tempNode->root);
                    if(tempNode->left != nullptr){
                        queue.push_back(tempNode->left);
                    }

                    if(tempNode->right != nullptr){
                        queue.push_back(tempNode->right);
                    }

                    n --;
                }
            }
        }

        bool find(Node* currentNode, int value){
            if(currentNode != nullptr){
                if(currentNode->root == value){
                    return true;
                }else{
                    if(value > currentNode->root){
                        return find(currentNode->right, value);
                    }else if(value < currentNode->root){
                        return find(currentNode->left, value);
                    }
                }
            }

            return false;
        }


        // void levelOrderTraversal(Node* currentNode){
        //     if(currentNode == nullptr){
        //         return;
        //     }

        //     std::vector<int> q;
        //     int n;
        //     Node* currNode;
        //     q.push_back(currentNode);
        //     while(q.size() != 0){
        //         n = q.size();
        //         while(n > 0){
        //             currNode = q.pop_back();
        //         }
        //     }
        // }
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
    std::cout << std::endl;
    std::cout << bst.height(bst.head) << "\n";
    bst.levelOrderTraversal(bst.head);
    bool result = bst.find(bst.head, 1);
    if(result){
        std::cout << "\nFound\n";
    }
    return 0;
}