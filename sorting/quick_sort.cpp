#include <iostream>
#include <vector>

std::vector<int> sort(std::vector<int> left, std::vector<int> right, int pivot){
    left.push_back(pivot);
    for(int i = 0; i<right.size(); i++){
        left.push_back(right[i]);
    }
    return left;
}


std::vector<int> quickSort(const std::vector<int> &arr){
    if(arr.size() == 1){
        return arr;
    }
    std::cout <<"test";
    int length = arr.size();
    int pivot = arr[length-1];
    std::vector<int> right;
    std::vector<int> left;
    for(int i = 0; i<length-1; i++){
        if(arr[i] > pivot){
            right.push_back(arr[i]);
        }else{
            left.push_back(arr[i]);
        }
    }
    return sort(quickSort(left), quickSort(right), pivot);
}


int main(){
    std::vector<int> test {9, 6, 2, 9, 1};
    std::vector<int> sorted;
    std::cout << "test\n";
    sorted = quickSort(test);
    for(int i = 0; i<test.size(); i++){
        std::cout << sorted[i] << " ";
    }
    std::cout << "\n";
    return 0;
}