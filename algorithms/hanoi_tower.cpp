#include <iostream>
#include <vector>


std::vector<std::string> split(std::string val, std::string criteria){
    std::vector<std::string> res;
    std::string line = "";
    for(int i = 0; i<val.size(); i++){
        if(val[i] == ' '){
            res.push_back(line);
            line = "";
        }else{
            line += val[i];
        }
    }

    return res;
}


std::string build_tower(int n, char source, char destination, char auxiliary){
    std::string res="";
    if(n == 0){
        res = source+"-"+destination;
        std::cout << source << "-" << destination << "\n";
        return res;
    }

    res = build_tower(n-1, source, auxiliary, destination) + " ";
    res += source+"-"+destination;
    std::cout << source << "-" << destination << "\n";
    res += " " + build_tower(n-1, auxiliary, destination, source);
    return res;
}


int main(){
    std::string v = "abc";
    std::string res;
    res = build_tower(3, v[0], v[1], v[2]);
    std::vector<std::string> arr;
    arr = split(res, " ");
}