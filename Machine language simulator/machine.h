#ifndef UNTITLED5_MACHINE_H
#define UNTITLED5_MACHINE_H
#include <bits/stdc++.h>
using namespace std;
int const memory_size = 256;
int const Register_size = 16;

class machine_language{
    string instruction;
    string memory[memory_size];
    string Register[Register_size];
public:
    int PC=0;
    vector<string> IR;
    machine_language();
    void Fetch(string instruct);
    void print_register();
    string  decimal_to_hexa( int decimal);
    void display_memory();
    bool is_valid(string instruct);
    void execute();
};


#endif //UNTITLED5_MACHINE_H
