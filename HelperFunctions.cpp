#include "HelperFunctions.h"
/*
int main(int argc, char *argv[]){
  HelperFuntions *help;
  help = new HelperFuntions();
  string bin = help->dectoBin("12");
  string hex = help->dectoHex("2545");
  string bin2 = help->hextoBin("5e111d36");
  string hex2 = help->bintoHex("1011110011010110101111100101010");
  cout << bin << endl;
  cout << hex << endl;
  cout << bin2 << endl;
  cout << hex2 << endl;
}

*/
string HelperFunctions::dectoBin(string input){

  stringstream dec(input);
  int n = 0;
  dec >> n;
  stringstream ss;
  for (int i = 31; i >= 0; i--){
    int k = n >> i;
    if(k&1)
      ss << "1";
    else
      ss << "0";
  }

  string asd = ss.str();
  return asd;

}

string HelperFunctions::hextoDec(string input){
  std::string newStr = HelperFunctions::dectoBin(input);
  std::string stri = HelperFunctions::bintoHex(newStr);
  return stri;

}

string HelperFunctions::dectoHex(string input){

  char hexaDeciNum[100];
  int i = 0;
  int n = 0;
  stringstream dec(input);
  dec >> n;
  stringstream ss;
  while(n!=0){
    int temp  = 0;
    temp = n % 16;

    if(temp < 10){
      hexaDeciNum[i] = temp + 48;
      i++;

    }else{
      hexaDeciNum[i] = temp + 55;
      i++;
    }
    n = n/16;
  }
  ss << "0x";
  for(int j=i-1; j>=0; j--){
    ss << hexaDeciNum[j];
  }

  string asd = ss.str();
  return asd;
}

string HelperFunctions::hextoBin(string input){
  stringstream ss;
  if((string(1, input[0]) == "0") && (string(1, input[1]) == "x")){
    input = input.substr(2);
  }
  long int i = 0;
  while (input[i]) {
    switch (input[i]) {
      case '0':
        ss << "0000";
        break;
      case '1':
        ss << "0001";
        break;
      case '2':
        ss << "0010";
        break;
      case '3':
        ss << "0011";
        break;
      case '4':
        ss << "0100";
        break;
      case '5':
        ss << "0101";
        break;
      case '6':
        ss << "0110";
        break;
      case '7':
        ss << "0111";
        break;
      case '8':
        ss << "1000";
        break;
      case '9':
        ss << "1001";
        break;
      case 'A':
      case 'a':
        ss << "1010";
        break;
      case 'B':
      case 'b':
        ss << "1011";
        break;
      case 'C':
      case 'c':
        ss << "1100";
        break;
      case 'D':
      case 'd':
        ss << "1101";
        break;
      case 'E':
      case 'e':
        ss << "1110";
        break;
      case 'F':
      case 'f':
        ss << "1111";
        break;
      default:
        cout << "\nInvalid hexadecimal digit " << input[i];
    }
    i++;
  }
  string asd = ss.str();
  return asd;
}


//void HelperFuntions::createMap(unordered_map<string, char> *um)
void HelperFunctions::createMap(map<string, char> *um)
{
    (*um)["0000"] = '0';
    (*um)["0001"] = '1';
    (*um)["0010"] = '2';
    (*um)["0011"] = '3';
    (*um)["0100"] = '4';
    (*um)["0101"] = '5';
    (*um)["0110"] = '6';
    (*um)["0111"] = '7';
    (*um)["1000"] = '8';
    (*um)["1001"] = '9';
    (*um)["1010"] = 'A';
    (*um)["1011"] = 'B';
    (*um)["1100"] = 'C';
    (*um)["1101"] = 'D';
    (*um)["1110"] = 'E';
    (*um)["1111"] = 'F';
}
string HelperFunctions::bintoHex(string bin){

  int l = bin.size();
  int t = bin.find_first_of('.');

  int len_left = t != -1 ? t : l;

  for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
    bin = '0' + bin;

  if (t != -1)
  {
    int len_right = l - len_left - 1;

    for (int i = 1; i <= (4 - len_right % 4) % 4; i++)
      bin = bin + '0';
  }

  //unordered_map<string, char> bin_hex_map;
  map<string, char> bin_hex_map;
  createMap(&bin_hex_map);

  int i = 0;
  string hex = "0x";

  while (1)
  {
    hex += bin_hex_map[bin.substr(i, 4)];
    i += 4;
    if (i == bin.size())
      break;

    if (bin.at(i) == '.')
    {
      hex += '.';
      i++;
    }
  }

  return hex;

}
