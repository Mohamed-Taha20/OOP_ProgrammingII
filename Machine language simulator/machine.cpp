#include "machine.h"

// convert an integer to binary
string int_to_binary(int n, string s)
{
    for (int i = 3; i >= 0; --i)
    {
        int k = n >> i;
        if (k & 1)
        {
            s = s + '1';
        }
        else
        {
            s = s + '0';
        }
    }
    return s;
}
// adding to binary numbers in two's complement format
string ADDING_2s(string comp1, string comp2)
{
    bool negative = false, negative1 = false;
    if (comp1[0] == '1')
        negative = true;
    if (comp2[0] == '1')
        negative1 = true;
    if (negative)
    {
        int ones = 0;
        // catching the first 1 in the binary string
        for (int i = comp1.size() - 1; i >= 0; --i)
        {
            if (comp1[i] == '1')
            {
                ones = i;
                break;
            }
        }
        // converting after the first 1 in the binary string
        for (int i = ones - 1; i >= 0; --i)
        {
            if (comp1[i] == '1')
            {
                comp1[i] = '0';
            }
            else
            {
                comp1[i] = '1';
            }
        }
    }
    else if (negative1)
    {
        int ones = 0;
        // catching the first 1 in the binary string
        for (int i = comp2.size() - 1; i >= 0; --i)
        {
            if (comp2[i] == '1')
            {
                ones = i;
                break;
            }
        }
        // converting after the first 1 in the binary string
        for (int i = ones - 1; i >= 0; --i)
        {
            if (comp2[i] == '1')
            {
                comp2[i] = '0';
            }
            else
            {
                comp2[i] = '1';
            }
        }
    }
    string summation = "";
    char reminder;
    // calculate the sum of the comp1 and comp2
    for (int i = comp1.size() - 1; i >= 0; --i)
    {
        int sum = (comp1[i] - '0') + (comp2[i] - '0');
        char sum_ = (sum + '0');
        if (sum > 1)
        {
            if (reminder == '1')
            {
                summation = '1' + summation;
                reminder = '1';
            }
            else
            {
                summation = '0' + summation;
                reminder = '1';
            }
        }
        else
        {
            if (reminder == '1')
            {
                if (sum_ == '1')
                {
                    summation = '0' + summation;
                    reminder = '1';
                }
                else
                {
                    summation = '1' + summation;
                    reminder = '0';
                }
            }
            else
            {
                summation = sum_ + summation;
                reminder = '0';
            }
        }
    }
    if (negative1 || negative)
    {
        // ignore the remainder if exists
        return summation;
    }
    else if (reminder == '1')
    {
        return '1' + summation;
    }
    else
    {
        return summation;
    }
}
// convert a hexadecimal string to its equivalent in binary format
string convert_hex_bin(string hex)
{
    string bin = "";
    for (int i = 0; i < hex.size(); ++i)
    {
        if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            bin = bin + int_to_binary(hex[i] - 'A' + 10, "");
        }
        else
        {
            bin = bin + int_to_binary(hex[i] - '0', "");
        }
    }
    return bin;
}
// convert a binary string to its hex representation
string convert_bin_hex(string bin)
{
    string hex = "";
    int sum = 0, sum1 = 0;
    char hexa;
    // marking the ones in the binary string and adding the digit wight to sum
    for (int i = bin.size() - 1, j = 0; i >= 4; --i, j++)
    {
        if (bin[i] == '1')
        {
            sum += pow(2, j);
        }
    }
    for (int i = 3, j = 0; i >= 0; --i, j++)
    {
        if (bin[i] == '1')
        {
            sum1 += pow(2, j);
        }
    }
    if (sum > 9)
    {
        hexa = (sum - 10 + 'A');
        hex = hex + hexa;
    }
    else
    {
        hexa = (sum + '0');
        hex = hex + hexa;
    }
    if (sum1 > 9)
    {
        hexa = (sum1 - 10 + 'A');
        hex = hexa + hex;
    }
    else
    {
        hexa = (sum1 + '0');
        hex = hexa + hex;
    }
    return hex;
}
// convert a decimal number to a hex string
string convert_dec_hex(int dec)
{
    string hex;
    if (dec > 9)
    {
        hex = (dec - 10 + 'A');
        return hex;
    }
    hex = (dec + '0');
    return hex;
}
// convert a binaey string to its decimal representation
int binaryToDecimal(const string &binaryStr)
{
    int decimalNum = 0;
    int power = binaryStr.length() - 1;
    // adding the digit`s wight to decimalNum
    for (char digit : binaryStr)
    {
        decimalNum += (digit - '0') * (1 << power);
        power--;
    }

    return decimalNum;
}

machine_language::machine_language()
{
    // setting all the array to zeros
    fill_n(memory, memory_size, "00");
    fill_n(Register, Register_size, "00");
}

void machine_language::Fetch(string instruct)
{
    // fetching each instraction to excute it
    instruction = instruct;
}

void machine_language::print_register()
{
    // printing all the registers for the user if he chooses to
    for (int i = 0; i < Register_size; ++i)
    {
        cout << "R" << convert_dec_hex(i) << ": " << Register[i] << "\n";
    }
}
// converting from decimal to hexadecimal representation
string machine_language::decimal_to_hexa(int decimal)
{
    stringstream sstring;
    sstring << hex << uppercase << decimal;
    return sstring.str();
}
// displaying all the memory for the user
void machine_language::display_memory()
{
    for (int i = 0; i < memory_size; ++i)
    {
        if (i % 15 == 0)
        {
            cout << "\n";
        }
        cout << decimal_to_hexa(i) << ": " << memory[i] << ", ";
    }
}
// check if the instraction is valid
// if not the program will terminate
bool machine_language::is_valid(string instruct)
{
    for (int i = 0; i < instruct.size(); ++i)
    {
        if (instruct[i] >= '0' && instruct[i] <= '9')
        {
            continue;
        }
        else if (instruct[i] >= 'A' && instruct[i] <= 'F')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void machine_language::execute()
{
    // checking if the instruction are valid before executing
    if (is_valid(instruction))
    {
        // LOAD the register R with the bit pattern found in the memory cell whose address is XY.
        if (instruction[0] == '1')
        {
            string alocate = instruction.substr(2, 2), regist = "";
            regist = (instruction[1]);
            Register[binaryToDecimal(convert_hex_bin(regist))] = memory[binaryToDecimal(convert_hex_bin(alocate))];
        }
        // LOAD the register R with the bit pattern XY.
        else if (instruction[0] == '2')
        {
            string alocate = instruction.substr(2, 2), regist = "";
            regist = (instruction[1]);
            Register[binaryToDecimal(convert_hex_bin(regist))] = alocate;
        }
        // STORE the bit pattern found in register R in the memory cell whose address is XY.
        else if (instruction[0] == '3')
        {
            string alocate = instruction.substr(2, 2), regist;
            regist = (instruction[1]);
            memory[binaryToDecimal(convert_hex_bin(alocate))] = Register[binaryToDecimal(convert_hex_bin(regist))];
        }
        // MOVE the bit pattern found in register R to register S.
        else if (instruction[0] == '4')
        {
            string alocate = instruction.substr(2, 1), regist = instruction.substr(3, 1);
            Register[binaryToDecimal(convert_hex_bin(alocate))] = Register[binaryToDecimal(convert_hex_bin(regist))];
        }
        // ADD the bit patterns in registers S and T as though they were two’s complement representations and leave the result in register R.
        else if (instruction[0] == '5')
        {
            string alocate = instruction.substr(2, 1), regist = instruction.substr(3, 1), mem, mem1;
            mem = Register[binaryToDecimal(convert_hex_bin(alocate))];
            mem1 = Register[binaryToDecimal(convert_hex_bin(regist))];
            Register[instruction[1] - '0'] = convert_bin_hex(ADDING_2s(convert_hex_bin(mem), convert_hex_bin(mem1)));
        }
        // JUMP to the instruction located in the memory cell at address XY if the bit pattern in register R is equal to the bit pattern in register number 0. Otherwise, continue with the normal sequence of execution. (The jump is implemented by copying XY into the program counter during the execute phase.)
        else if (instruction[0] == 'B')
        {
            if (Register[0] == Register[instruction[1] - '0'])
            {
                PC = binaryToDecimal(convert_hex_bin(instruction.substr(2, 2)));
            }
        }
        // HALT execution and display menu so user can select wich future to show.
        else if (instruction[0] == 'C')
        {
            int option;
            cout << "1-Display the status of registers\n"
                 << "2-Display PC\n"
                 << "3-Display IR\n"
                 << "4-Display Memory\n"
                 << "5-Display all features\n";
            cout << "Please choose one of this option press 0 or 1 or 2 or 3 or 4 to select any option of them: ";
            cin >> option;
            if (option == 1)
            {
                print_register();
            }
            else if (option == 2)
            {
                cout << decimal_to_hexa(PC);
            }
            else if (option == 3)
            {
                cout << "IR: " << IR[IR.size() - 2];
            }
            else if (option == 4)
            {
                display_memory();
            }
            else if (option == 5)
            {
                print_register();
                cout << "\n";
                cout << "PC: " << decimal_to_hexa(PC) << "\n";
                cout << "IR: " << IR[IR.size() - 2] << "\n";
                display_memory();
            }
            exit(0);
        }
    }
    else
    {
        cout << "invalid instruction";
        exit(0);
    }
}
