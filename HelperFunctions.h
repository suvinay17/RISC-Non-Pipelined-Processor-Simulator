#ifndef __HELPERFUNCTIONS_H__
#define __HELPERFUNCTIONS_H__

#include <string>
#include <iostream>
#include <sstream>
//#include <bits/stdc++.h>
#include <map>
using namespace std;
class HelperFunctions{

  public:
    int binaryToDecimal(string input);
    string dectoBin(string input);
    string dectoHex(string input);
    string hextoBin(string input);
    string bintoHex(string bin);
    int hextoDec(string input);

  private:

    //void createMap(unordered_map<string, char> *um);
    void createMap(map<string, char> *um);
};

#endif
