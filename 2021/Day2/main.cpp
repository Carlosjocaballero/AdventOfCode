#include <iostream>
#include <fstream>
#include <string>

int main(){
    int aim = 0;
    int horizontalPos = 0;
    int depth = 0;
    std::ifstream input;
    input.open("input.txt", std::ios::in);
    if(input.is_open()){
        std::string word;
        while(input >> word){
            if(word == "forward"){
                input >> word;
                horizontalPos += std::stoi(word);
                depth += aim*std::stoi(word);
            }
            if(word == "up"){
                input >> word;
                aim -= std::stoi(word);
            }
            if(word == "down"){
                input >> word;
                aim += std::stoi(word);
            }
        }
    }
    std::cout << horizontalPos*depth << std::endl;
}