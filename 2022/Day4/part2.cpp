#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

bool overlap(std::vector<int> pairA, std::vector<int> pairB){
    std::unordered_set<int> uSet;
    for(const auto& x : pairA){
        uSet.insert(x);
    }

    for(const auto& x : pairB){
        if(uSet.count(x)){
            return true;
        }
    }

    return false;
}

int main(){
    int numOverlap = 0;
    std::fstream input;
    bool pastDash1 = false;
    input.open("input.txt", std::ios::in);
    if(input.is_open()){
        std::string line;
        while(input >> line){
            std::string num1 = "";
            std::string num2 = "";
            std::string num3 = "";
            std::string num4 = "";
            // true means it has not reached
            int countDash = 0;
            bool dash = false;
            bool comma = false;
            for(int i = 0; i < line.length(); i++){
                if(line[i] == '-'){
                    dash = true;
                    countDash++;
                    continue;
                }
                if(line[i] == ','){
                    comma = true;
                    continue;
                }
                if(dash == false && comma == false && countDash == 0){
                    num1.push_back(line[i]);
                }
                if(dash == true && comma == false && countDash == 1){
                    num2.push_back(line[i]);
                }
                if(dash == true && comma == true && countDash == 1){
                    num3.push_back(line[i]);
                }
                if(dash == true && comma == true && countDash == 2){
                    num4.push_back(line[i]);
                }
                if(i == line.length() - 1){
                    dash = false;
                    comma = false;
                    countDash = 0;
                }
            }
            std::vector<int> pair1;
            for(int i = stoi(num1); i <= stoi(num2); i++){
                pair1.push_back(i);
            }

            std::vector<int> pair2;
            for(int i = stoi(num3); i <= stoi(num4); i++){
                pair2.push_back(i);
            }

            if(overlap(pair1, pair2) || overlap(pair2, pair1)){
                numOverlap++;
            }

        }
    }
    else std::cout << "ERROR: File could not open" << std::endl;

    std::cout << numOverlap << std::endl;
}