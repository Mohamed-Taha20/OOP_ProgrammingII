#include <bits/stdc++.h>
#include "machine.h"
using namespace std;

int main(){
    string instruction,machine_file,line;
    cout << "Please enter you machine file: ";
    cin >> machine_file;
    ifstream file(machine_file);
    machine_language instructions;
    while(getline(file,line)){
        string instruction_machine="";
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ' || line[i] == 'x' || i == 0) {
                continue;
            } else {
                if (line[i] == '0') {
                    if (line[i-1] == 'x' || line[i-1] == '0') {
                        instruction_machine += line[i];
                    }
                } else {
                    instruction_machine += line[i];
                }
            }
        }
        instructions.IR.push_back(instruction_machine);
    }
    for (int i = 0; i < instructions.IR.size(); ++i) {
        instructions.Fetch(instructions.IR[i]);
        instructions.execute();
        instructions.PC+=2;
    }
}