#ifndef __SLL_H__
#define __SLL_H__

#include <string>
#include <iostream>
using namespace std;

class SLL{

  public:
   void setInput(string input);
   string shift(string input);

  private:
   string myInput;
   string myOutput;
};

#endif
