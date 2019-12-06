#include "SymbolTable.h"
#include <fstream>
#include <iostream>

SymbolTable::SymbolTable()
{
}

//First pass through the .asm file to assign memory
//addresses to the symbols 
void SymbolTable::readASM(string filename)
{
    HelperFunctions help;
    ifstream infile;
    infile.open(filename.c_str());

    if(!infile)
    {
        cerr << "unable to open file" << endl;
        exit(0);
    }

    //int startMem = 4194304;     //starting address of symbols program
    int startMem = 0x400000;     //starting address of symbols program
                                //equals hex value 0x400000
    int track = 0;
    int place;
    string line;
    string hexAddress;
    while(!infile.eof())
    {
        getline(infile, line);
        place = line.find(":");
        if(place != -1) {
            int decAddress = track + startMem;     //finds decimal value of mem location
            //Symbols temp = {help.dectoHex(to_string(decAddress)), line.substr(0,place)};
            //Symbols temp = {help.dectoHex(to_string(decAddress)), line.substr(0,place)};
            Symbols temp = {line.substr(0,place), startMem};
            mySymbol.push_back(temp);
            cout << temp.name << "\t"<< temp.address << endl; 
        }
        //track += 4;
        startMem += 4;
    }
    infile.close();
}

int SymbolTable::getSymbol(string symbol)
{
    for(unsigned int i = 0; i < mySymbol.size(); i++)
    {
        if(mySymbol[i].name == symbol)
            return mySymbol[i].address;
    }
    return -1;
}
