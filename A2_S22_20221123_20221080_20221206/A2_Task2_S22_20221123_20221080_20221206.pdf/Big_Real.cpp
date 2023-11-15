#include "Big_Real.h"

string removeLeadingZeros(const string &input)
{
    // remove any extra zero in the output
    string result = input;
    size_t firstNonZero = result.find_first_not_of('0');
    if (firstNonZero != std::string::npos)
    {
        result = result.substr(firstNonZero);
    }
    else
    {
        result = "0";
    }

    return result;
}
void alignDecimalPoints(string &num1, string &num2)
{
    // to handle the the dot position and to equal to string with each other
    int Dot1_Pos = num1.find('.');
    int Dot2_Pos = num2.find('.');

    int the_decimal_part1, th_decimal_part2 ;
    if(Dot1_Pos != string::npos){
        the_decimal_part1 = num1.length() - Dot1_Pos - 1 ;
    }
    else {
        the_decimal_part1 = 0;
    }
    if(Dot2_Pos != string::npos){
        th_decimal_part2 = num2.length() - Dot2_Pos - 1 ;
    }
    else {
        th_decimal_part2 = 0;
    }
    int maxFracDigits = max(the_decimal_part1, th_decimal_part2);

    while (the_decimal_part1 < maxFracDigits)
    {
        num1 += '0';
        the_decimal_part1++;
    }

    while (th_decimal_part2 < maxFracDigits)
    {
        num2 += '0';
        th_decimal_part2++;
    }

    if (Dot1_Pos == 0)
        num1 = "0" + num1;

    if (Dot2_Pos == 0)
        num2 = "0" + num2;

    int totalWidth = max(num1.length(), num2.length());

    while (num1.length() < totalWidth)
        num1 = "0" + num1;

    while (num2.length() < totalWidth)
        num2 = "0" + num2;
}
bool BigReal:: isValidReal(string s){
    // check for if the string has a character not consist extra dot or sign or alphabet character
    int valid = 0,sign=0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '.' || (s[i] >= 'a' && s[i] <= 'z')){
            valid++;
        }
        else if(s[i] == '+' || s[i] == '-'){
            sign++;
        }
    }
    if(valid > 1){
        return 0;
    }
    else if(sign > 1){
        return 0;
    }
    return 1;
}
BigReal BigReal::operator+ (BigReal num2){
    bool dot1=false,dot2=false,neg1=false,neg2=false;
    int index_dot1,index_dot2;
    // if there is a positive or negative sign then remove it and add two number and adding the sign at the end of calculation
    if(number[0] == '+')number.erase(0,1);
    if(num2.number[0] == '+')num2.number.erase(0,1);
    if(number[0] == '-'){
        neg1 = true;number.erase(0,1);}
    if(num2.number[0] == '-'){
        neg2 = true;num2.number.erase(0,1);}
    if(number[0] == '.')number.insert(0,"0");
    if(num2.number[0] == '.')num2.number.insert(0,"0");
    // preserve the dot position
    for (int i = number.size()-1; i >= 0; --i) {
        if(number[i] == '.'){
            dot1 = true;
            index_dot1 = i;
            break;
        }
    }
    for (int i = num2.number.size()-1; i >= 0; --i) {
        if(num2.number[i] == '.'){
            dot2=true;
            index_dot2 = i;
            break;
        }
    }
    BigReal sum_number;
    // adding two positive integar only
    if(!dot1 && !dot2 && !neg1 && !neg2){
        // to make each of integer equal
        if(number.size() > num2.number.size()){
            while (number.size() > num2.number.size()){
                num2.number = '0'+ num2.number;
            }
        }
        else if(number.size() < num2.number.size()){
            while (number.size() < num2.number.size()){
                number = '0' + number;
            }
        }
        char res;
        int reminder=0,sum;
        // adding two integer
        for (int i = number.size()-1; i >= 0; --i) {
            sum = (number[i] - '0') + (num2.number[i] - '0');
            // if summation of two digit is greater than 9 then there are a carry
            if(sum > 9){
                // if there is a carry then should reserve it the next sum of digit
                if(reminder > 0){
                    sum+=reminder;
                    sum %= 10;
                    reminder = 1;
                    res = (sum + '0');
                    sum_number.number = res+sum_number.number;
                }
                else{
                    // if the carry does not exist then add two digit easly
                    sum %= 10;
                    reminder = 1;
                    res = (sum + '0');
                    sum_number.number = res+sum_number.number;
                }
            }
            else{
                // check if there is a carry from the privous addition
                //if there is then add it to summation of two digit
                if(reminder > 0){
                    if(sum + reminder > 9){
                        if(i > 0){
                            sum = ((sum)+(reminder));
                            sum %= 10;
                            reminder = 1;
                            res = (sum + '0');
                            sum_number.number = res+sum_number.number;
                        }
                        else{
                            sum = ((sum)+(reminder));
                            sum %= 10;
                            reminder = 1;
                            res = (sum + '0');
                            sum_number.number = res+sum_number.number;
                        }
                    }
                    else{
                        res = ((sum)+(reminder)) + '0';
                        sum_number.number = res+sum_number.number;
                        reminder=0;
                    }

                }
                else{
                    res = (sum + '0');
                    sum_number.number = res+sum_number.number;
                    reminder=0;
                }
            }
        }
        // if there is a carry after finishing the calculation then we add it to the begining of the string
        if(reminder > 0){
            sum_number.number = '1'+sum_number.number;
            index = true;
        }
        return sum_number;
    }
        // adding two positive number integer and fraction
    else if(!dot1 && dot2 && !neg1 && !neg2){
        // adding all number after the dot and dot to the output object then deleting the digits from the fraction number
        for (int i = num2.number.size()-1; i >= index_dot2; --i) {
            sum_number.number = num2.number[i] + sum_number.number;
            num2.number.erase(i,1);
        }
        // adding two integer number then adding to the object
        BigReal sum = (*this+num2);
        sum_number.number = sum.number + sum_number.number;
        return sum_number;
    }
        // adding two positive number fraction and integer
    else if (dot1 && !dot2 && !neg1 && !neg2){
        // adding all number after the dot and dot to the output object then deleting the digits from the fraction number
        for (int i = number.size()-1; i >= index_dot1; --i) {
            sum_number.number = number[i] + sum_number.number;
            number.erase(i,1);
        }
        // adding two integer number then adding to the object
        BigReal sum = (*this+num2);
        sum_number.number = sum.number + sum_number.number;
        return sum_number;
    }
        // adding two fraction number
    else if(dot1 && dot2 && !neg1 && !neg2){
        // separating the digits before and after the dot
        string size1="",size2="",size3="",size4="";
        size1 = number.substr(0,index_dot1);
        size3 = number.substr(index_dot1+1,number.size() - index_dot1 - 1);
        size2 = num2.number.substr(0,index_dot2);
        size4 = num2.number.substr(index_dot2+1,num2.number.size() - index_dot2 - 1);
        // equal the digit after separate them
        if(size1.size() > size2.size()){
            while(size1.size() > size2.size()){
                size2 = '0' + size2;
            }
        }
        else if(size1.size() < size2.size()){
            while(size1.size() < size2.size()){
                size1 = '0' + size1;
            }
        }
        if(size3.size() > size4.size()){
            while(size3.size() > size4.size()){
                size4 = size4 + '0';
            }
        }
        else if(size3.size() < size4.size()){
            while(size3.size() < size4.size()){
                size3 = size3 + '0';
            }
        }
        // transform the fraction numbers to integer then adding them
        number = (size1 + size3);
        num2.number = (size2 + size4);
        BigReal sum = (*this + num2);
        sum_number.number = sum_number.number + sum.number;
        // check if there is a carry then the position of dot will shifting to the right
        if(index){
            sum_number.number.insert(max(index_dot2,index_dot1)+1,".");
        }
        else{
            sum_number.number.insert(max(index_dot2,index_dot1),".");
        }
        return sum_number;
    }
        // adding two negative number
    else if(neg1 && neg2){
        // adding two fraction and negative number
        if(dot1 && dot2){
            sum_number = (*this+num2);
            sum_number.number = '-' + sum_number.number;
            return sum_number;
        }
            // adding two negative integer number
        else if(!dot1 && !dot2){
            sum_number = (*this+num2);
            sum_number.number = '-' + sum_number.number;
            return sum_number;
        }
            // adding negative fraction and negative integer
        else if(dot1 && !dot2){
            sum_number = (*this+num2);
            sum_number.number = '-' + sum_number.number;
            return sum_number;
        }
            // adding negative integer and negative fraction
        else if(!dot1 && dot2){
            sum_number = (*this+num2);
            sum_number.number = '-' + sum_number.number;
            return sum_number;
        }
    }
        // adiing positive and negative  number
    else if(!neg1 && neg2){
        sum_number = (*this - num2);
        return sum_number;
    }
        // adding negative and positive number
    else if(neg1 && !neg2){
        if(*this < num2){
            sum_number = (*this - num2);
            sum_number.number.erase(0,1);
            return sum_number;
        }
        else if(*this > num2){
            sum_number = (*this - num2);
//                sum_number.number = '-' + sum_number.number;
            return sum_number;
        }
        else{
            sum_number = (*this - num2);
            return sum_number;
        }
    }
}
BigReal BigReal::operator- (BigReal num2){
    // checking the sign of the two number and if there a dot
    bool Dot_for_num2 = false,neg1=false,neg2=false;bool Dot_for_number = false;
    if(number[0] == '-')neg1=true;
    if(num2.number[0] == '-')neg2=true;
    for(int i = 0 ; i < num2.number.length() ; i++){
        if(num2.number[i] == '.'){
            Dot_for_num2 = true;
            break;
        }
    }
    for(int i = 0 ; i < number.length() ; i++){
        if(number[i] == '.'){
            Dot_for_number = true;
            break;
        }
    }
    // if the two number has a dot or one of them then add a dot
    if((Dot_for_number && Dot_for_num2) || (!Dot_for_number && Dot_for_num2) || (Dot_for_number && !Dot_for_num2)){
        if(!Dot_for_num2) num2.number += '.';
        if(!Dot_for_number) number += '.';
    }
    BigReal sum_number;
    // subtract two positive number
    if(!neg1 && !neg2){
        // reposition the dot and make length of two number equal to each other such that the dots are in the same index
        alignDecimalPoints(num2.number, number);
        // subtracting from the bigger number
        if (num2.number > number)
        {
            for (int i = num2.number.size() - 1; i >= 0; i--)
            {
                if(num2.number[i] == '.'){
                    sum_number.number = '.' + sum_number.number;
                    continue;
                }
                    // check if digit greater than the adjacent digit
                else if ((int)num2.number[i] < (int)number[i])
                {
                    for (int j = i-1; j >= 0; j--)
                    {
                        // if the digit is smaller then the adjacent then we check if the next is non zero
                        if (num2.number[j] > '0')
                        {
                            // should borrow one from the next digit and blus 10 to index i digit
                            num2.number[j] = ((int)num2.number[j] - 1);
                            num2.number[i] = ((int)num2.number[i] + 10);
                            // making all digit before i digit equal to 9 if all of them are zeros
                            for (int k = j + 1; k < i; k++)
                            {
                                if(num2.number[k] == '.') continue;
                                num2.number[k] = '9';
                            }
                            break;
                        }
                    }
                }
                // subtracting two digits easly
                char c = (((int)num2.number[i] - (int)number[i]) + '0');
                sum_number.number = c + sum_number.number;
            }
            // removing extra zeros from number
            sum_number.number = removeLeadingZeros(sum_number.number);
            // if the first digit after subtract is '.' then we add zero to the first
            if(sum_number.number[0] == '.' ){
                sum_number.number = '0' + sum_number.number;
            }
            sum_number.number = '-' + sum_number.number;
        }
        else
        {
            for (int i = number.size() - 1; i >= 0; i--)
            {
                if(number[i] == '.'){
                    sum_number.number = '.' + sum_number.number;
                    continue;
                }
                else if ((int)number[i] < (int)num2.number[i])
                {
                    for (int j = i-1; j >= 0; j--)
                    {
                        // if the digit is smaller then the adjacent then we check if the next is non zero
                        if (number[j] > '0')
                        {
                            number[j] = ((int)number[j] - 1);
                            number[i] = ((int)number[i] + 10);
                            // making all digit before i digit equal to 9 if all of them are zeros
                            for (int k = j + 1; k < i; k++)
                            {
                                if(number[k] == '.') continue;
                                number[k] = '9';
                            }
                            break;
                        }
                    }
                }
                // subtracting two digits easly
                char c = (((int)number[i] - (int)num2.number[i]) + '0');
                sum_number.number = c + sum_number.number;
            }
            // removing extra zeros from number
            sum_number.number = removeLeadingZeros(sum_number.number);
            if(sum_number.number[0] == '.' ){
                sum_number.number = '0' + sum_number.number;
            }
        }
//            if(!Dot_for_num2 && !Dot_for_number){
//                sum_number.number.erase(sum_number.number.size()-1,1);
//            }
        return sum_number;
    }
    else if(neg1 && neg2){
        num2.number.erase(0,1);
        sum_number = (*this + num2);
        return sum_number;
    }
    else if(!neg1 && neg2){
        num2.number.erase(0,1);
        sum_number = (*this + num2);
        return sum_number;
    }
    else if(neg1 && !neg2){
        number.erase(0,1);
        sum_number = (*this + num2);
        sum_number.number = '-' + sum_number.number;
        return sum_number;
    }
}
bool BigReal::operator< (BigReal num2){
    // counting the number of digit before and after dot to compare them
    int digit1=0,digit2=0,dot,dot2,digit3=0,digit4=0;
    // checking two positive number
    if(number[0] == '-' && num2.number[0] == '-'){
        for (int i = 0; i < number.size(); ++i) {
            if(number[i] == '.'){
                dot=i;
                break;
            }
            else{
                digit1++;
            }
        }
        for (int i = 0; i < num2.number.size(); ++i) {
            if(num2.number[i] == '.'){
                dot2=i;
                break;
            }
            else{
                digit2++;
            }
        }
        for (int i = dot+1; i < number.size(); ++i) {
            digit3++;
        }
        for (int i = dot2+1; i < num2.number.size(); ++i) {
            digit4++;
        }
        // check the size of the number of digit before the dot
        if(digit1 > digit2){
            return 1;
        }
        else if(digit1 < digit2){
            return 0;
        }
        else{
            bool equal = false;
            // check if the number is greater or smaller than the second number or equal
            for (int i = 0; i < dot; ++i) {
                if(number[i] > num2.number[i]){
                    return 1;
                }
                else if(number[i] < num2.number[i]){
                    return 0;
                }
                else{
                    equal = true;
                }
            }
            // if the size of the digits is equal then we check the digit after the dot
            if(equal){
                // equal the size of two nuumber to be able to check
                if(digit3 < digit4){
                    while(number.size() < num2.number.size()){
                        number = number+'0';
                    }
                }
                else if(digit3 > digit4){
                    while(number.size() > num2.number.size()){
                        num2.number = num2.number+'0';
                    }
                }
                // check if the number is greater or smaller than the second number or equal
                for (int i = dot+1; i < number.size(); ++i) {
                    if(number[i] > num2.number[i]){
                        return 1;
                    }
                    else if(number[i] < num2.number[i]){
                        return 0;
                    }
                    else{
                        equal = true;
                    }
                }
            }
            if(equal){
                return 0;
            }
        }
    }
        // checking two negative number
    else if(number[0] != '-' && num2.number[0] != '-'){
        // counting the number of digit before and after dot to compare them
        for (int i = 0; i < number.size(); ++i) {
            if(number[i] == '.'){
                dot=i;
                break;
            }
            else{
                digit1++;
            }
        }
        for (int i = 0; i < num2.number.size(); ++i) {
            if(num2.number[i] == '.'){
                dot2=i;
                break;
            }
            else{
                digit2++;
            }
        }
        for (int i = dot+1; i < number.size(); ++i) {
            digit3++;
        }
        for (int i = dot2+1; i < num2.number.size(); ++i) {
            digit4++;
        }
        // check the size of the number of digit before the dot
        if(digit1 > digit2){
            return 0;
        }
        else if(digit1 < digit2){
            return 1;
        }
        else{
            // check if the number is greater or smaller than the second number or equal
            bool equal = false;
            for (int i = 0; i < dot; ++i) {
                if(number[i] > num2.number[i]){
                    return 0;
                }
                else if(number[i] < num2.number[i]){
                    return 1;
                }
                else{
                    equal = true;
                }
            }
            // if the size of the digits is equal then we check the digit after the dot
            if(equal){
                // equal the size of two nuumber to be able to check
                if(digit3 < digit4){
                    while(number.size() < num2.number.size()){
                        number = number+'0';
                    }
                }
                else if(digit3 > digit4){
                    while(number.size() > num2.number.size()){
                        num2.number = num2.number+'0';
                    }
                }
                // check if the number is greater or smaller than the second number or equal
                for (int i = dot+1; i < number.size(); ++i) {
                    if(number[i] > num2.number[i]){
                        return 0;
                    }
                    else if(number[i] < num2.number[i]){
                        return 1;
                    }
                    else{
                        equal = true;
                    }
                }
            }
            if(equal){
                return 0;
            }
        }
    }
        // if the first number is negative then true
    else if(number[0] == '-' && num2.number[0] != '-'){
        return 1;
    }
        // if the second number is negative then false
    else if(number[0] != '-' && num2.number[0] == '-'){
        return 0;
    }
}
bool BigReal::operator> (BigReal num2){
    // chack if the number is not smaller than or equal to the num2
    if(!(*this < num2) && !(*this == num2)){
        return 1;
    }
    return 0;
}
bool BigReal::operator== (BigReal num2){
    // check if there is a digit not equal to its adjacent
    for (int i = 0; i < number.size(); ++i) {
        if(number[i] != num2.number[i]){
            return 0;
        }
    }
    return 1;
}
ostream& operator<<(ostream& out, BigReal num){
    // to make user able to apply cout on two objects of class
    return out << num.number;
}
BigReal::BigReal():number(""){}
BigReal::BigReal(string s){
    if(isValidReal(s)){
        number = s;
    }
    else{
        cout << "INVALID NUMBER\n";
        exit(0);
    }
}