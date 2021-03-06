#include "Parser.h"
#include "RegisterTable.h"
#include "DataMemory.h"

/*
afs   int main(int argc, char *argv[]){
   Parser *pp;

   pp = new Parser();
   pp->ParseFile("test.txt");
   }
 */
Parser::Parser(){
  program_input = " ";
  memory_contents_input = " ";
  register_file_input = " ";
  output_mode = " ";
  //debug_mode;
  //print_memory_contents = false;
  //write_to_file = false;
  //output_file = false;
}
//Accessor methods that return the input configurations
string Parser::getProgram_input(){ return program_input; }
string Parser::getMemory_contents_input(){ return memory_contents_input; }
string Parser::getRegister_file_input(){ return register_file_input; }
string Parser::getOutput_mode(){ return output_mode; }
bool Parser::getDebug_mode(){ return debug_mode; }
bool Parser::getPrint_memory_contents(){ return print_memory_contents; }
bool Parser::getWrite_to_file() { return write_to_file; }
string Parser::getOutput_file(){ return output_file; }


//This methods parses the register file line by line
void Parser::ParseRegFile(string filename, RegisterTable &table){
  ifstream in;
  in.open(filename.c_str());
  if(in.bad()){
    cout << "Bad File";

  }else{
    string line;
    while(getline(in,line)){
      //cout << "line: " << line << endl;
      if(string(1, line[0]) == "#" || line.length() == 0){
        continue;
      }

      size_t pos = line.find(":");
      string param = line.substr(0, pos);
      string value = line.substr(pos+1);
      table.setRegValueByNumber(param, value);
    }  
  }
  in.close();

}

//THis method parses the memory file
void Parser::ParseMemFile(string filename, DataMemory &mem){
ifstream in;
  in.open(filename.c_str());
  if(in.bad()){
    cout << "Bad File";

  }else{
    string line;
    while(getline(in,line)){
      //cout << "line: " << line << endl;
      if(string(1, line[0]) == "#" || line.length() == 0){
        continue;
      }

      size_t pos = line.find(":");
      string param = line.substr(0, pos);
      string value = line.substr(pos+1);
      mem.setData(param, value);

    }

  }
  in.close();
}


//This method parses the configuration file
void Parser::ParseConfigFile(string filename){
  ifstream in;
  in.open(filename.c_str());
  if(in.bad()){
    cout << "Bad File";

  }else{
    string line;
    while(getline(in,line)){
      //cout << "line: " << line << endl;
      if(string(1, line[0]) == "#" || line.length() == 0){
        continue;
      }

      size_t pos = line.find("=");
      string param = line.substr(0, pos);
      string value = line.substr(pos+1);
      //cout << "param: " << param << endl;
      //cout << "value: " << value << endl;
      if(param.compare("program_input") == 0)
      { program_input = value; }

      else if(param.compare("memory_contents_input") == 0)
      { memory_contents_input = value; }

      else if(param.compare("register_file_input") == 0)
      { register_file_input = value; }

      else if(param.compare("output_mode") == 0)
      { output_mode = value; }

      else if(param.compare("debug_mode") == 0){
        if(value.compare("true") == 0){
          debug_mode = true;
        }else{
          debug_mode = false;
        }
      }
      else if(param.compare("print_memory_contents") == 0){
        if(value.compare("true") == 0){
          print_memory_contents = true;
        }else{
          print_memory_contents = false;
        }
      }
      else if(param.compare("write_to_file") == 0){
        if(value.compare("true") == 0){
          write_to_file = true;
        }else{
          write_to_file = false;
        }
      }
      else if(param.compare("output_file") == 0){
        output_file = value;
        }

    }
    cout << "program_input: "<< program_input << endl;
    cout << "memory_contents_input: "<< memory_contents_input << endl;
    cout << "register_file_input: "<< register_file_input << endl;
    cout << "output_mode: "<< output_mode << endl;
    cout << "debug_mode: " << boolalpha << debug_mode << endl;
    cout << "print_memory_contents: " << boolalpha << print_memory_contents << endl;
    cout << "write_to_file: " << boolalpha << write_to_file << endl;
    cout << "output_file: " << boolalpha << output_file << endl;

  

  }

  in.close();

}
