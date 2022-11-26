#include <iostream>
#include <cstdio>

int* sort(int arr[], int size){
    bool swaped = true;
    int temp;
    for(int i = 0; i<size; i++){
        for(int j = 0; j<(size-i-1); j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main(){
    int arr[] = {8,3,1,11,5,6,4,5};
    int* k;
    k = sort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++){
        std::cout << k[i] << " ";
    }
    std::cout << "\n";
}