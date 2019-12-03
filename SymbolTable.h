#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include "HelperFunctions.h"
#include <string>

using namespace std;

struct Symbols{
    string name;
    string address;
};

class SymbolTable{
    public:
        SymbolTable();

        void readASM(string filename);
        string getSymbol(string symbol);

    private:
        Symbols mySymbol[100];
};

#endif
