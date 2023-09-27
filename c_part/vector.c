#include <stdio.h>
#include <stdlib.h>

struct{
    int size;
    int *arr;
}Vector;

void push_back(int *a, int value, int size){
    if(size == 0){
        a = malloc(sizeof(int));
        a[0] = value;
        return;
    }
    int *temp = malloc(size*sizeof(int));
    free(a);
    size++;
    a = malloc(size*sizeof(int));
    int i;
    for(i = 0; i<size; i++){
        a[i] = temp[i];
    }
    a[i] = value;
    free(temp);
}

void show(int *a, int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int *arr;
    int size = 0;
    push_back(arr, 1, size);
    push_back(arr, 2, size);
    show(arr, size);
}