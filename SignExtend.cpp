#include "SignExtend.h"
#include <string>
//Written by Jimmy
//Default constructor
SignExtend::SignExtend()
{
}


//this functions gets a binary string of size 16, the methods extends it to a string of size 32
string SignExtend::extend(string input)
{ 
    //strings to append based on if positive or negative
    string one = "1111111111111111";
    string zero = "0000000000000000";
    
    //detect if the value is positive or negative and sign extends the result
    char posneg = input[0];
    string output = "";
    if(posneg == '1')
        output += one;
    else
        output += zero;

    output.append(input);
    return output;
}
