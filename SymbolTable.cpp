#include "SymbolTable.h"
#include <fstream>
#include <iostream>
//writen by Jimmy

//empty constructor
SymbolTable::SymbolTable()
{
}

//First pass through the .asm file to assign memory
//addresses to the symbols
void SymbolTable::readASM(string filename)
{
    ifstream infile;
    infile.open(filename.c_str());

    if(!infile)
    {
        cerr << "unable to open file" << endl;
        exit(0);
    }

    int startMem = 4194304;     //equals hex value 0x400000

    int track = 0;
    int place;
    HelperFunctions help;
    string line;
    string hexAddress;

    //searches the .asm file for symbols and stores the address for them
    while(!infile.eof())
    {
        getline(infile, line);
        place = line.find(":");
        if(place != -1) {
            int decAddress = track + startMem;     //finds decimal value of mem location
            Symbols temp = {line.substr(0,place), help.dectoHex(to_string(decAddress))};
            mySymbol.push_back(temp);
            cout << temp.name << "\t"<< temp.address << endl;
        }
        //track += 4;
        startMem += 4;
    }
    infile.close();
}


//returns the address of the symbol inputed by the user
//returns nothing if the symbol is not real
string SymbolTable::getSymbol(string symbol)
{
    for(unsigned int i = 0; i < mySymbol.size(); i++)
    {
        cout << mySymbol[i].address << endl;
        if(mySymbol[i].name == symbol)
            return mySymbol[i].address;
    }
    return "";
}
