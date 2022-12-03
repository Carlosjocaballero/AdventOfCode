#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int depthIncreaseII(const std::vector<int>& digits){
    int increaseCount{0};

    for(int i = 0; i < digits.size() - 3; i++){
        int firstSum = digits[i] + digits[i+1] + digits[i+2];
        int secondSum = digits[i+1] + digits[i+2] + digits[i+3];
        if(secondSum > firstSum) increaseCount++;
    }
    
    return increaseCount;
}

int main(){
    std::vector<int> digits;
    std::ifstream input;
    input.open("input.txt", std::ios::in);
    if(input.is_open()){
        std::string tp;
        while(std::getline(input, tp)){
            digits.push_back(std::stoi(tp));
        }
    }

    std::cout << "Answer: " << depthIncreaseII(digits) << std::endl;

}