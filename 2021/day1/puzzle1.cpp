#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int depthIncrease(const std::vector<int>& digits){
    int currDecreases = 0;

    for(int i = 1; i < digits.size(); i++){
        if(digits[i-1] < digits[i]) currDecreases++;
    }

    return currDecreases;
}

int main(){
    std::vector<int> digits;
    std::fstream newfile;
    newfile.open("input.txt", std::ios::in);
    if(newfile.is_open()){
        std::string tp;
        while(std::getline(newfile, tp)){
            digits.push_back(std::stoi(tp));
        }    
    }

    std::cout << "Answer: " << depthIncrease(digits) << std::endl;
}