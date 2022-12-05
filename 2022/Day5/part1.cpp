#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <stack>
#include <vector>

void printStack(std::stack<char> stk){
    std::stack<char> temp = stk;
    while(!temp.empty()){
        std::cout << temp.top() << std::endl;
        temp.pop();
    }
}

int main(){
    std::vector<std::stack<char>> crates(9);
    std::vector<char> crate = {'M', 'J', 'C', 'B', 'F', 'R', 'L', 'H'};
    for(auto x : crate) crates[0].push(x);
    
    crate.clear();
    crate.push_back('Z'); crate.push_back('C'); crate.push_back('D');
    for(auto x : crate) crates[1].push(x);

    crate.clear();
    crate.push_back('H'); crate.push_back('J'); crate.push_back('F'); crate.push_back('C');
    crate.push_back('N'); crate.push_back('G'); crate.push_back('W');
    for(auto x : crate) crates[2].push(x);
    
    crate.clear();
    crate.push_back('P'); crate.push_back('J'); crate.push_back('D'); crate.push_back('M');
    crate.push_back('T'); crate.push_back('S'); crate.push_back('B');
    for(auto x : crate) crates[3].push(x);

    crate.clear();
    crate.push_back('N'); crate.push_back('C'); crate.push_back('D'); crate.push_back('R');
    crate.push_back('J');
    for(auto x : crate) crates[4].push(x);

    crate.clear();
    crate.push_back('W'); crate.push_back('L'); crate.push_back('D'); crate.push_back('Q');
    crate.push_back('P'); crate.push_back('J'); crate.push_back('G'); crate.push_back('Z');
    for(auto x : crate) crates[5].push(x);

    crate.clear();
    crate.push_back('P'); crate.push_back('Z'); crate.push_back('T'); crate.push_back('F');
    crate.push_back('R'); crate.push_back('H'); 
    for(auto x : crate) crates[6].push(x);

    crate.clear();
    crate.push_back('L'); crate.push_back('V'); crate.push_back('M'); crate.push_back('G');
    for(auto x : crate) crates[7].push(x);

    crate.clear();
    crate.push_back('C'); crate.push_back('B'); crate.push_back('G'); crate.push_back('P');
    crate.push_back('F'); crate.push_back('Q'); crate.push_back('R'); crate.push_back('J');
    for(auto x : crate) crates[8].push(x);


    std::fstream input;
    input.open("input.txt", std::ios::in);
    if(input.is_open()){
        for(int i = 0; i < 10; i++){
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
        } 
        std::string line;
        while(input >> line){
            int move, from, to;
            input>>line;
            move = stoi(line);  
            input >> line;
            input >> line;
            from = stoi(line);
            input >> line;
            input >> line;
            to = stoi(line);
            for(int i = 0; i < move; i++){
                crates[to-1].push(crates[from-1].top());
                crates[from-1].pop();
            }
        }   
    }
    else std::cout << "ERROR: Could not open file" << std::endl;

    std::string answ;

    for(int i = 0; i < crates.size(); i++){
        answ.push_back(crates[i].top());
    }

    std::cout << answ << std::endl;


}