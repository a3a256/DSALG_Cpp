#include <iostream>
#include <stdlib.h>


class Vector{
    int* main;
    int* temp;
    int size=0;
    public:

        void push_back(int val){
            if(size == 0){
                main = (int*)malloc(sizeof(int));
                size++;
                main[0] = val;
                return;
            }
            copy();
            size++;
            free(main);
            main = (int*)malloc(size*sizeof(int));
            int i;
            for(i=0; i<size-1; i++){
                main[i] = temp[i];
            }
            main[size-1] = val;
            free(temp);
        }

        void insert(int index, int value){
            if(size == 0){
                push_back(value);
                return;
            }
            copy();
            size++;
            free(main);
            main = (int*)malloc(size*sizeof(int));
            int i;
            for(i=0; i<index; i++){
                main[i] = temp[i];
            }
            main[index] = value;
            for(i=index+1; i<size; i++){
                main[i] = temp[i-1];
            }
        }

        void show(){
            int i;
            for(i=0; i<size; i++){
                std::cout << main[i] << " ";
            }
            std::cout << "\n";
        }

    private:

        void copy(){
            int i;
            temp = (int*)malloc(size*sizeof(int));
            for(i=0; i<size; i++){
                temp[i] = main[i];
            }
        }
};

int main(){
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.insert(1, 5);
    v.show();
}