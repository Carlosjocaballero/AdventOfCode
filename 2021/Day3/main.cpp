#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

int BinToDig(std::string binary){
    int dig = 0;
    for(int i = binary.size() - 1; i >= 0; i--){
        if(binary[i] == '1') dig += std::pow(2, binary.size() - 1 - i);
    }
    return dig;
}

int main(){
    std::vector<std::string> binaries;
    std::ifstream input;
    input.open("input.txt", std::ios::in);
    if(input.is_open()){
        std::string binary;
        while(input >> binary){
            binaries.push_back(binary);
        }
    }

    std::vector<std::string> cBinaries = binaries;

    std::string gammaRate;
    int sum1 = 0;
    int sum0 = 0;
    int sum_0 = 0;
    int sum_1 = 0;


    for(int i = 0; i < binaries[0].length(); i ++){
        for(int j = 0; j < binaries.size(); j++){
            if(binaries[j][i] == '0') sum0++;
            if(binaries[j][i] == '1') sum1++;
        }

        std::vector<std::string> temp;

        char freq = (sum0 > sum1) ? '0' : '1';

        for(int k = 0; k < binaries.size(); k++){
            if(binaries[k][i] == freq) temp.push_back(binaries[k]);
        }


        binaries = temp;
        

        if(binaries.size() == 2) break;

        sum1=0;
        sum0=0;
    }

    for(int i = 0; i < cBinaries[0].size(); i++){
        for(int j = 0; j < cBinaries.size(); j++){
            if(cBinaries[j][i] == '0') sum_0++;
            if(cBinaries[j][i] == '1') sum_1++;
        }

        std::vector<std::string> temp;


        char freq = (sum_0 > sum_1) ? '1' : '0';

        for(int k = 0; k < cBinaries.size(); k++){
            if(cBinaries[k][i] == freq) temp.push_back(cBinaries[k]);
        }

        cBinaries = temp;


        if(cBinaries.size() <= 2) break;

        sum_0 =0;
        sum_1 =0;
        
    }



    std::string oxigenGeneratorRating = (binaries[0][binaries.size()-1] == '1') ? binaries[1] : binaries[0];

    int oxigenGeneratorRatingDec = BinToDig(oxigenGeneratorRating);

    int co2ScrubberRatingDec = BinToDig(cBinaries[0]);



    std::cout << oxigenGeneratorRatingDec << std::endl;
    std::cout << co2ScrubberRatingDec << std::endl;
    std::cout << oxigenGeneratorRatingDec*co2ScrubberRatingDec << std::endl;
}