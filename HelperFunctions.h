#ifndef __HELPERFUNCTIONS_H__
#define __HELPERFUNCTIONS_H__

#include <string>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
class HelperFuntions{

  public:

    string dectoBin(string input);
    string dectoHex(string input);
    string hextoBin(string input);
    string bintoHex(string bin);

  private:

    void createMap(unordered_map<string, char> *um);
};

#endif
