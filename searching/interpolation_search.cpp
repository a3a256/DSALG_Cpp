#include <iostream>
#include <vector>


int search_vector(const std::vector<int> &vect, int lo, int hi, int target){
    if (lo == hi){
        if(vect[lo] == target){
            return lo;
        }else{
            return -1;
        }
    }
    int mid = lo + (target - vect[lo]) * (hi - lo)/(vect[hi] - vect[lo]);
    if (vect[mid] == target){
        return mid;
    }else if(vect[mid] > target){
        return search_vector(vect, lo, mid-1, target);
    }else if(vect[mid] < target){
        return search_vector(vect, mid+1, hi, target);
    }
}


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

    std::vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(6);
    arr1.push_back(9);
    arr1.push_back(12);

    // std::cout << arr1[0] << "\n";

    std::cout << search_vector(arr1, (int)0, (int)arr1.size()-1, (int)9) << "\n";

    return 0;
}