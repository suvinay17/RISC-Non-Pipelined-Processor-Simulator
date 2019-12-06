#include "SignExtend.h"
#include <string>
//Written by Caleb
//Default constructor
SignExtend::SignExtend()
{
}


//this functions gets a binary string of size 16, the methods extends it to a string of size 32
string SignExtend::extend(string input)
{   //initializing a helper function
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
