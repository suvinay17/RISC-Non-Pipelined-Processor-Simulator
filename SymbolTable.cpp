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
    ifstream infile;
    infile.open(filename.c_str());

    if(!infile)
    {
        cerr << "unable to open file" << endl;
        exit(0);
    }

    int startMem = 4194304;
    //string startMem = "400000";     //starting address of symbols program
                                //equals hex value 0x400000
    int track = 0;
    int place;
    HelperFunctions help;
    string line;
    string hexAddress;
    while(!infile.eof())
    {
        getline(infile, line);
        place = line.find(":");
        if(place != -1) {
            int decAddress = track + startMem;     //finds decimal value of mem location
            Symbols temp = {line.substr(0,place), help.dectoHex(to_string(decAddress))};
            //Symbols temp = {help.dectoHex(to_string(decAddress)), line.substr(0,place)};
            //Symbols temp = {line.substr(0,place), startMem};
            mySymbol.push_back(temp);
            cout << temp.name << "\t"<< temp.address << endl;
        }
        //track += 4;
        startMem += 4;
    }
    infile.close();
}

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
