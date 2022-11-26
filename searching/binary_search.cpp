#include <iostream>

int search(int arr[], int start, int end, int target){
    int mid = (start+end)/2;
    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] > target){
        return search(arr, start, mid-1, target);
    }else if(arr[mid] < target){
        return search(arr, mid+1, end, target);
    }
    return -1;
}

int main(){
    int vals[] = {12, 19, 21, 24, 29, 32, 33, 37, 45, 90};
    std::cout << search(vals, (int)0, (int)9, (int)21) << "\n";
    return 0;
}