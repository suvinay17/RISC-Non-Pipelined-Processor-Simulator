#include "SignExtend.h"
#include <string>

SignExtend::SignExtend()
{
}

string SignExtend::extend(string input)
{
    HelperFunctions help;
    //string binary =  help.hextoBin(input);
    string one = "1111111111111111";
    string zero = "0000000000000000";
    
    char posneg = input[0];
    string output = "";
    if(posneg == '1')
        output += one;
    else
        output += zero;

    output.append(input);
    return output;
}
