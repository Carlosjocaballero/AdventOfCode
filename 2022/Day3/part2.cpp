#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main(){
    std::fstream input;
    input.open("input.txt", std::ios::in);
    int total{0};
    if(input.is_open()){
        std::string line;
        while(input >> line){
            char ch;
            std::unordered_set<char> group1;
            std::unordered_set<char> group2;
            std::unordered_set<char> group3;

            for(const auto& x : line){
                group1.insert(x);
            }

            input >> line;

            for(const auto& x : line){
                if(group1.count(x)){
                    group2.insert(x);
                }
            }

            input >> line;

            for(const auto& x : line){
                if(group2.count(x)){
                    ch = x;       
                }
            }
            
            if(int(ch) >= 97 && int(ch)<= 122){
                std::cout << int(ch) - 97 + 1 << std::endl;
                total+=int(ch) - 97 + 1;
            }
            else if(int(ch) >= 65 && int(ch) <= 90){
                std::cout << int(ch) - 38 << std::endl;
                total += int(ch) - 38;
            } 

        }
    }
    std::cout << total << std::endl;

}