#include <iostream>
#include <cstdio>

int* sort(int arr[], int size){
    int i = 1;
    int j;
    int temp;
    while(i < size){
        j = i;
        while(j>0 && arr[j-1]>arr[j]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j --;
        }
        i ++;
    }
    return arr;
}

int main(){
    int arr[] = {9, 2, 5, 8, 10, 13, 7, 3, 29};
    int* k;
    k = sort(arr, (int)(sizeof(arr)/sizeof(arr[0])));
    for(int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++){
        std::cout << k[i] << " ";
    }
    std::cout << "\n";
    return 0;
}