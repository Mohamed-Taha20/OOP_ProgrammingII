#include <bits/stdc++.h>
using namespace std;
int const memory_size = 256;
int const Register_size = 16;
int counter=0;
string binary(int n,string s){
    for (int i = 3; i >= 0; --i) {
        int k = n >> i;
        if(k&1){
            s=s+'1';
        }
        else{
            s=s+'0';
        }
    }
    return s;
}
string ADDING_2s(string comp1,string comp2){
    bool negative = false,negative1 = false;
    if(comp1[0] == '1')negative=true;
    if(comp2[0] == '1')negative1=true;
    if(negative){
        int ones=0;
        for (int i = comp1.size()-1; i >= 0; --i) {
            if (comp1[i] == '1'){
                ones = i;
                break;
            }
        }
        for (int i = ones - 1; i >= 0; --i) {
            if(comp1[i] == '1'){
                comp1[i] = '0';
            }
            else{
                comp1[i] = '1';
            }
        }
    }
    else if(negative1){
        int ones=0;
        for (int i = comp2.size()-1; i >= 0; --i) {
            if (comp2[i] == '1'){
                ones = i;
                break;
            }
        }
        for (int i = ones - 1; i >= 0; --i) {
            if(comp2[i] == '1'){
                comp2[i] = '0';
            }
            else{
                comp2[i] = '1';
            }
        }
    }
    string summation="";char reminder;
    for (int i = comp1.size()-1; i >= 0; --i) {
        int sum = (comp1[i]-'0') + (comp2[i]-'0');
        char sum_ = (sum+'0');
        if(sum > 1){
            if(reminder == '1'){
                summation = '1' + summation;
                reminder = '1';
            }
            else{
                summation = '0' + summation;
                reminder = '1';
            }

        }
        else{
            if(reminder == '1'){
                if(sum_ == '1'){
                    summation = '0' + summation;
                    reminder = '1';
                }
                else{
                    summation = '1' + summation;
                    reminder = '0';
                }
            }
            else{
                summation = sum_ + summation ;
                reminder = '0';
            }
        }
    }
    if(negative1 || negative){
        return summation;
    }
    else if(reminder == '1'){
        return '1'+summation;
    }
    else{
        return summation;
    }
}
int convert_str(string converter){
    int convert=0;
    if(converter.size() == 2){
        convert+=(converter[0]-'0')*10;
        convert+=(converter[1]-'0');
    }
    else if(converter.size() == 1){
        convert+=(converter[0]-'0');
    }
    else if(converter.size() == 3){
        convert+=(converter[0]-'0')*100;
        convert+=(converter[1]-'0')*10;
        convert+=(converter[2]-'0');
    }
    return convert;
}
string convert_hex_bin(string hex){
    string bin="";
    for (int i = 0; i < hex.size(); ++i) {
        if(hex[i] >= 'A' && hex[i] <= 'F'){
            bin = bin + binary(hex[i] - 'A' + 10,"");
        }
        else{
            bin = bin + binary(hex[i] - '0',"");
        }
    }
    return bin;
}
string convert_bin_hex(string bin){
    string hex="";int sum=0,sum1=0;char hexa;
    for (int i = bin.size()-1,j=0; i >= 4; --i,j++) {
        if(bin[i] == '1'){
            sum+= pow(2,j);
        }
    }
    for (int i = 3,j=0; i >= 0; --i,j++) {
        if(bin[i] == '1'){
            sum1+= pow(2,j);
        }
    }
    if(sum > 9){
        hexa = (sum - 10 + 'A');
        hex = hex + hexa;
    }
    else{
        hexa = (sum+'0');
        hex = hex + hexa;
    }
    if(sum1 > 9){
        hexa = (sum1 - 10 + 'A');
        hex = hexa + hex;
    }
    else{
        hexa = (sum1+'0');
        hex = hexa + hex;
    }
    return hex;
}
string convert_dec_hex(int dec){
    string hex;
    if(dec > 9){
        hex = (dec - 10 + 'A');
        return hex;
    }
    hex = (dec+'0');
    return hex;
}
int binaryToDecimal(const string& binaryStr) {
    int decimalNum = 0;
    int power = binaryStr.length() - 1;

    for (char digit : binaryStr) {
        decimalNum += (digit - '0') * (1 << power);
        power--;
    }

    return decimalNum;
}
class machine_language{
protected:
    string instruction;
    string memory[memory_size];
    string Register[Register_size];
public:
    vector<string> IR;
    machine_language(){
        fill_n(memory,memory_size,"00");
        fill_n(Register,Register_size,"00");
    }
    void set_instruction(string instruct){
        instruction = instruct;
    }
    void print_register(){
        for (int i = 0; i < Register_size; ++i) {
            cout << "R"<< convert_dec_hex(i) << ": " << Register[i] << "\n";
        }
    }
    string  decimal_to_hexa( int decimal){
        stringstream sstring;
        sstring << hex<< uppercase << decimal;
        return sstring.str();
    }
    void display_memory() {
        for (int i = 0; i < memory_size; ++i) {
            if(i % 15 == 0){
                cout << "\n";
            }
            cout << decimal_to_hexa(i) << ": " << memory[i] << ", " ;
        }
    }
    void execute(){
        if(instruction[0] == '1'){
            string alocate = instruction.substr(2,2),regist = "";
            regist=(instruction[1]);
            Register[binaryToDecimal(convert_hex_bin(regist))] = memory[convert_str(alocate)];
        }
        else if(instruction[0] == '2'){
            string alocate = instruction.substr(2,2),regist = "";
            regist=(instruction[1]);
            Register[binaryToDecimal(convert_hex_bin(regist))] = alocate;
        }
        else if(instruction[0] == '3'){
            string alocate = instruction.substr(2,2),regist;
            regist=(instruction[1]);
            memory[binaryToDecimal(convert_hex_bin(alocate))] = Register[binaryToDecimal(convert_hex_bin(regist))];
        }
        else if(instruction[0] == '4'){
            string alocate = instruction.substr(2,1),regist = instruction.substr(3,1);
            Register[binaryToDecimal(convert_hex_bin(alocate))] = Register[binaryToDecimal(convert_hex_bin(regist))];
        }
        else if(instruction[0] == '5'){
            string alocate = instruction.substr(2,1),regist = instruction.substr(3,1),mem,mem1;
            mem = Register[binaryToDecimal(convert_hex_bin(alocate))];mem1 = Register[binaryToDecimal(convert_hex_bin(regist))];
            Register[instruction[1]-'0'] = convert_bin_hex(ADDING_2s(convert_hex_bin(mem), convert_hex_bin(mem1)));
        }
        else if(instruction[0] == 'B'){

        }
        else if(instruction[0] == 'C'){
            int option;
            cout << "1-Display the status of registers\n" << "2-Display PC\n" << "3-Display IR\n" << "4-Display Memory\n" << "5-Display all features\n";
            cout << "Please choose one of this option press 0 or 1 or 2 or 3 or 4 to select any option of them: ";
            cin >> option;
            if(option == 1){
                print_register();
            }
            else if(option == 2){
                cout << decimal_to_hexa(counter);
            }
            else if(option == 3){
                cout << "IR: " << IR[IR.size()-2];
            }
            else if(option == 4){
                display_memory();
            }
            else if(option == 5){
                print_register();cout << "\n";
                cout << "PC: " << decimal_to_hexa(counter) << "\n";
                cout << "IR: " << IR[IR.size()-2] << "\n";
                display_memory();
            }
            exit(0);
        }
    }
};
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
        instructions.set_instruction(instructions.IR[i]);
        instructions.execute();
        counter+=2;
    }
}