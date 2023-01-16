#include <iostream>
#include <vector>

std::vector<std::vector<int>> permutations(std::vector<int> arr){
    std::vector<std::vector<int>> res;
    if(arr.size() == 1){
        res.push_back(arr);
        return res;
    }
    int last;
    last = arr.at(arr.size()-1);
    arr.pop_back();
    std::vector<std::vector<int>> perms;
    perms = permutations(arr);
    std::vector<int> novel;
    for(int p = 0; p<perms.size(); p++){
        for(int i = 0; i<perms[p].size(); i++){
            for(int j = 0; j<i; j++){
                novel.push_back(perms[p][j]);
            }
            novel.push_back(last);
            for(int j = i; j < perms[p].size(); j++){
                novel.push_back(perms[p][j]);
            }
            res.push_back(novel);
            std::vector<int>().swap(novel);
        }
    }

    return res;
}


int main(){
    std::vector<int> arr {1,3,5,2};
    std::vector<std::vector<int>> permute;
    permute = permutations(arr);
    for(int i = 0; i<permute.size(); i++){
        for(int j = 0; j<permute[0].size(); j++){
            std::cout << permute[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}