#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// A -> rock
// B -> paper
// C -> scissors

// X -> lose
// Y -> draw
// Z -> win

// rock     -> 1
// paper    -> 2
// scissors -> 3

// lose -> 0
// draw -> 3
// win  -> 6

int main() {
    std::string opponent;
    std::string decision;
    int totalScore{0};
    std::fstream input;
    input.open("input.txt", std::ios::in);
    if(input.is_open()){
        std::string letter;
        while(input >> letter){
            opponent = letter;
            input >> letter;
         decision = letter;
            if(opponent == "A" && decision == "Y"){
                totalScore += 1 + 3;
            }
            if(opponent == "A" && decision == "Z"){
                totalScore += 2 + 6;
            }
            if(opponent == "B" && decision == "X"){
                totalScore += 1;
            }
            if(opponent == "B" && decision == "Z"){
                totalScore += 3 + 6;
            }
            if(opponent == "C" && decision == "X"){
                totalScore += 2;
            }
            if(opponent == "C" && decision == "Y"){
                totalScore += 3 + 3;
            }
            if(opponent == "A" && decision == "X"){
                totalScore += 3;
            }
            if(opponent == "B" && decision == "Y"){
                totalScore += 2 + 3;
            }
            if(opponent == "C" && decision == "Z"){
                totalScore += 1 + 6;
            }
        }
    }
    std::cout << totalScore << std::endl;

}