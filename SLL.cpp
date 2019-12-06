#include "SLL.h"
//Written by caleb suvinay Jimmy, the SLL emulates the SLL portion of a processor

/*int main(int argc, char *argv[]){
  SLL *sl;
  sl = new SLL();
  string slll = sl->shift("10010010010010010010010010010010");
  cout << "01001001001001001001001001001000" << endl;
  cout << slll << endl;

}
*/

//Mutator method for setting the input to SLL
void SLL::setInput(string input){
  myInput = input;
}


//The method that shifts the binary string to the left
string SLL::shift(string input){
  //cout << input.length() << endl;
  if(input.length() == 32){
    for(int i = 2; i < input.length(); i++){
      input[i-2] = input[i];
    }
    input[30] = '0';
    input[31] = '0';
    }else{
      input += "00";
    }

  myOutput = input;
  return myOutput;
}
