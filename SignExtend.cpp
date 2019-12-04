#include "SignExtend.h"
#include <string>

SignExtend::SignExtend()
{
}

string SignExtend::extend(string input)
{
    HelperFunctions help;
    string binary =  help.hextoBin(input);
    string posneg = binary.substr(0,1);
    string output;
    for(int i = 0; i < 16; i++)
        output.append(posneg.substr(0,1));   output.append(input);
    output.append(binary);
    //string outputHex = help.bintoHex(output);
    //return outputHex;
}
