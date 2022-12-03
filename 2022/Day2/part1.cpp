#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// A,X -> rock
// B,Y -> paper
// C,Z -> scissors

// rock     -> 1
// paper    -> 2
// scissors -> 3

// lose -> 0
// draw -> 3
// win  -> 6

int main() {
    std::string opponent;
    std::string me;
    std::string result;
    int score =0;
    std::vector<int> allScores;
    int totalScore{0};
    std::fstream input;
    input.open("input.txt", std::ios::in);
    if(input.is_open()){
        std::string letter;
        while(input >> letter){
            opponent = letter;
            input >> letter;
            me = letter;
            std::cout << opponent << " " << me << std::endl;
            if(opponent == "A" && me == "Y"){
                totalScore += 2 + 6;
            }
            if(opponent == "A" && me == "Z"){
                totalScore += 3;
                std::cout << totalScore << std::endl;
            }
            if(opponent == "B" && me == "X"){
                totalScore += 1;
            }
            if(opponent == "B" && me == "Z"){
                totalScore += 6 + 3;
            }
            if(opponent == "C" && me == "X"){
                totalScore += 1 + 6;
            }
            if(opponent == "C" && me == "Y"){
                totalScore += 2;
            }
            if(opponent == "A" && me == "X"){
                totalScore += 3 + 1;
            }
            if(opponent == "B" && me == "Y"){
                totalScore += 3 + 2;
            }
            if(opponent == "C" && me == "Z"){
                totalScore += 3 + 3;
            }
        }
    }
    std::cout << totalScore << std::endl;

}