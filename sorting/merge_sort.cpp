#include <iostream>
#include <cstdio>
#include <vector>

std::vector<int> combine(const std::vector<int> &left, const std::vector<int> &right){
    int i = 0;
    int j = 0;
    std::vector<int> res;
    while(i<left.size() && j<right.size()){
        if(left[i] < right[j]){
            res.push_back(left[i]);
            i ++;
        }else{
            res.push_back(right[j]);
            j ++;
        }
    }

    while(i < left.size()){
        res.push_back(left[i]);
        i ++;
    }
    while(j < right.size()){
        res.push_back(right[j]);
        j++;
    }
    return res;
}

std::vector<int> sort(const std::vector<int> &vec){
    if(vec.size() == 1){
        return vec;
    }

    int middle = vec.size()/2;
    std::vector<int> right;
    std::vector<int> left;
    for(int i = 0; i<middle; i++){
        left.push_back(vec[i]);
    }
    for(int j = middle; j<vec.size(); j++){
        right.push_back(vec[j]);
    }

    return combine(sort(left), sort(right));
}

int* merge(int left[], int right[], int l, int r){
    if(l == 1){
        return left;
    }
    if(r == 1){
        return right;
    }
    // std::cout << l << "c\n";
    int i = 0;
    int j = 0;
    static int res[50];
    int v = 0;
    while(i < l && j < r){
        if(left[i] < right[j]){
            res[v] = left[i];
            // std::cout << "v" << res[v] << "\n";
            i++;
            v++;
        }else{
            res[v] = right[j];
            j++;
            v++;
        }
    }
    if(i < l){
        while(i < l){
            res[v] = left[i];
            i ++;
            v ++;
        }
    }
    if(j < r){
        while(j < r){
            res[v] = right[j];
            j ++;
            v ++;
        }
    }
    for(int k = 0; k<(l+r); k++){
        std::cout << res[k] << " ";
    }
    std::cout << "\n";
    return res;
}

int* mergeSort(int arr[], int length){
    if(length == 1){
        // std::cout << "last" << arr[0] << "\n";
        return arr;
    }

    int middle = length/2;
    // std::cout << middle << "\n";
    int left[middle];
    int right[length-middle];
    for(int i = 0; i<middle; i++){
        left[i] = arr[i];
    }
    int v = 0;
    for(int i = middle; i<length; i++){
        right[v] = arr[i];
        v ++;
    }
    int* b;
    b = merge(mergeSort(left, middle), mergeSort(right, (length-middle)), middle, (length-middle));
    return b;
}


int main(){
    std::vector<int> arr {1, 5, 2, 9, 6};
    std::vector<int> sorted;
    sorted = sort(arr);
    std::cout << "check" << "\n";
    for(int i = 0; i<arr.size(); i++){
        std::cout << sorted[i] << " ";
    }
    std::cout << "\n";
    return 0;
}