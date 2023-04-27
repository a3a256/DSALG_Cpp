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