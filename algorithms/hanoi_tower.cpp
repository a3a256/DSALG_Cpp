#include <iostream>


void build_tower(int n, char source, char destination, char auxiliary){
    if(n == 0){
        std::cout << source << "-" << destination << "\n";
    }

    build_tower(n-1, source, auxiliary, destination);
    std::cout << source << "-" << destination << "\n";
    build_tower(n-1, auxiliary, destination, source);
}


int main(){
    std::string v = "abc";
    build_tower(3, v[0], v[1], v[2]);
}