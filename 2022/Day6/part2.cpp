// For part 1, change all the 14s to 4.

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main() {
    std::fstream input;
    int answ{0};
    std::string line;
    input.open("input.txt", std::ios::in);
    if(input.is_open()){
        input >> line;
    }
    else std::cout << "ERROR: file could not open" << std::endl;
    std::cout << "size: " << line.length() << std::endl;

    for(int i = 0; i < line.length() - 14; i++){
        std::unordered_set<char> uSet;
        uSet.insert(line[i]);
        for(int j = 1; j < 14; j++){
            uSet.insert(line[i+j]);
        }
        if(uSet.size() == 14){
            answ = i + 14;
            break;
        }
    }

    std::cout << "answer: " <<  answ << std::endl;
}