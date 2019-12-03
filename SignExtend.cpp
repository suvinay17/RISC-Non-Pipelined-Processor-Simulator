#include "HelperFunctions.h"
#include <string>

SignExtend::SignExtend()
{
}

string SignExtend::extend(string input)
{
    string binary =  HelperFunctions.hextoBin(input);
    string posneg = binary.substr(0,1);
    string output;
    for(int i = 0; i < 16; i++)
        output.append(posneg.substr(0,1));
    output.append(binary);
    string outputHex = HelperFunctions.bintoHex(output);
    return outputHex;
}
