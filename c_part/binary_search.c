#include <stdio.h>

int search_recursion(int* array, int size, int start, int end, int target){
    if(target < array[0] || target > array[size-1]){
        return -1;
    }
    int mid = (start+end)/2;
    if(array[mid] == target){
        return mid;
    }
    if(array[mid]<target){
        return search_recursion(array, size, mid+1, end, target);
    }
    if(array[mid]>target){
        return search_recursion(array, size, start, mid-1, target);
    }
    return -1;
}


int main(){
    int arr[5] = {5, 7, 9, 12, 16};
    int size = 5;
    int pos = search_recursion(arr, size, 0, size-1, 7);

    printf("The position is %d\n", pos);
    return 0;
}