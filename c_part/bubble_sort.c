#include <stdio.h>

int* sorted(int *arr, int size){
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
    const int size = 5;
    int arr[size] = {3, 2, 7, 1, 9};
    int res[size] = sorted(arr, size);

    for(int i=0; i<size; i++){
        printf("%d ", res[i]);
    }
    printf("\n");
}