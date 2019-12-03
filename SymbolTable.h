#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include "HelperFunctions.h"
#include <string>
#include <vector>
#include <stdlib.h>

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
        vector<Symbols> mySymbol;
};

#endif
