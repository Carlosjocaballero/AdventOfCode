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
            char shared;
            std::unordered_set<char> uSet;
            std::cout << line << std::endl;
            
            std::string half = line.substr(0, line.length()/2);
            std::string otherHalf = line.substr(line.length()/2);

            std::cout << half << " " << otherHalf << std::endl;

            for(const auto& x : half){
                uSet.insert(x);
            }

            for(auto x : uSet){
                std::cout << x << " ";
            }
            std::cout << std::endl;

            for(const auto& x : otherHalf){
                if(uSet.count(x)){
                    shared = x; std::cout << shared << std::endl; break;
                }
            }

            std::cout << shared << ": ";
            if(int(shared) >= 97 && int(shared)<= 122){
                std::cout << int(shared) - 97 + 1 << std::endl;
                total+=int(shared) - 97 + 1;
            }
            else if(int(shared) >= 65 && int(shared) <= 90){
                std::cout << int(shared) - 38 << std::endl;
                total += int(shared) - 38;
            } 
        }

        std::cout << total << std::endl;
    }
    else std::cout << "ERROR: file did not open"; 
}