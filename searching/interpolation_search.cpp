#include <iostream>


int search(int arr[], int lo, int hi, int target){
    if (lo == hi){
        if (arr[lo] == target){
            return lo;
        }else{
            return -1;
        }
    }
    int mid = lo + (target - arr[lo]) * (hi - lo)/(arr[hi] - arr[lo]);
    if (arr[mid] == target){
        return mid;
    }else if(arr[mid] > target){
        return search(arr, lo, mid-1, target);
    }else if(arr[mid] < target){
        return search(arr, mid+1, hi, target);
    }
}



int main(){

    int arr[] = {1, 4, 6, 8, 9, 12, 16};

    std::cout << search(arr, (int)0, (int)6, (int)4) << '\n';

    return 0;
}