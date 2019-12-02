#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Parser{

  public:
    Parser();
    void ParseConfigFile(string filename);
    void ParseRegFile(string filename);
    void ParseMemFile(string filename);
    string getProgram_input();
    string getMemory_contents_input();
    string getRegister_file_input();
    string getOutput_mode();
    bool getDebug_mode();
    bool getPrint_memory_contents();
    bool getWrite_to_file();
    bool getOutput_file();


  private:
    string program_input;
    string memory_contents_input;
    string register_file_input;
    string output_mode;
    bool debug_mode;
    bool print_memory_contents;
    bool write_to_file;
    bool output_file;

};

#endif
