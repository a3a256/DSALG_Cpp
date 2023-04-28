#include <iostream>
#include <vector>

std::vector<std::vector<int>> combinations(std::vector<int> vec, int n){
    std::vector<std::vector<int>> l;
    std::vector<int> temp;
    if(n == 0){
        return l;
    }
    std::vector<int> remlst;
    std::vector<std::vector<int>> remain_comb;
    remlst = vec;

    std::cout << vec[0];

    int i, j, m;

    for(i=0; i<vec.size(); i++){
        m = vec[i];
        remlst.erase(remlst.begin());
        remain_comb = combinations(remlst, n-1);
        temp.push_back(m);
        for(j=0; j<remain_comb.size(); j++){
            temp.insert(temp.end(), remain_comb[j].begin(), remain_comb[j].end());
            l.push_back(temp);
        }
    }

    return l;
}

int main(){
    std::vector<int> test = {1, 2, 3, 4, 5};
    int n=3;
    std::vector<std::vector<int>> res;
    res = combinations(test, n);
    int i, j;
    std::cout << "check";
    std::cout << res.size();
    for(i=0; i<res.size(); i++){
        for(j=0; j<res[i].size(); j++){
            std::cout << res[i][j] << " check ";
        }
        std::cout << "\n";
    }

    return 0;
}