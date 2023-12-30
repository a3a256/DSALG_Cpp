#include <stdio.h>
#include <stdlib.h>

int* sorted(int *arr, const int size){
    int sorted = 0, i, temp;
    while(sorted == 0){
        sorted = 1;
        for(i=1; i<size; i++){
            if(arr[i] < arr[i-1]){
                sorted = 0;
                temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
            }
        }
    }

    return arr;
}


int main(){
    int arr[5] = {3, 2, 7, 1, 9};
    int* res = (int*)malloc(5*sizeof(int));
    res = sorted(arr, 5);

    for(int i=0; i<5; i++){
        printf("%d ", res[i]);
    }
    printf("\n");
}