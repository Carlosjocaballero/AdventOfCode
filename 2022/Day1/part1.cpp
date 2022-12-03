#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> calories;
    int sum = 0;
    std::fstream input;
    input.open("input.txt", std::ios::in);
    if(input.is_open()){
        std::string line;
        while(std::getline(input, line)){
            if(line == "") {
                calories.push_back(sum);
                sum = 0;
            } 
            else{
                sum += std::stoi(line);
            }
        }
    }

    int max = 0;

    std::sort(calories.begin(), calories.end());

    std::vector<int> topCalories;

    for(int i = 1; i <= 3; i++){
        topCalories.push_back(calories[calories.size() - i]);
    }

    int topSum;

    for(auto& x: topCalories){
        topSum += x;
    }

    std::cout << topSum << std::endl;

}