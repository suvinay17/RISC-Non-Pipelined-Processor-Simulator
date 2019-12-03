//.h file for ALU
//Suvinay Bothra
//CMSC301
#ifndef __ALU_H__
#define __ALU_H__

#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>


using namespace std;

class ALU {

	public:

		//Constructor
		ALU();

		// Sets the first input to the ALU
		//	inp_1 is a 32-bit binary string
		inline void setInput_1(string inp_1) { input_1 = inp_1; }

		// Sets the second input to the ALU
		// inp_2 	is a 32-bit binary string
		inline void setInput_2(string inp_2) { input_2 = inp_2; }

		// Sets the operation to be performed on the inputs
		// 	string operation to be performed: "add", "sub", or "compare"
		inline void setOperation(string op) { operation = op; }

		// Performs operation on the ALU inputs
		void conductOperation();

		// Returns the output of the operation performed on the given inputs
		// 32-bit binary string result of operation is returned
		inline string getResult() { return result; }

	private:

		string operation;	// Operation to be done from "add", "sub", or "compare"

		string input_1;		// First input to ALU (binary string)
		string input_2;		// Second input to ALU
		string result; 		// Result of the given operation on the inputs

		// Returns "equal" if input1 and input2 are equal, else "not_equal"
		string compare(string input_1, string input_2);

		// Subtracts input2 from input1  and returns the result
		string subtract(string input_1, string input_2);

		// Adds input1 and input2 (binary numbers represented as strings) and returns the result
		string add(string input_1, string input_2);

		// Helper functions

		// Converts 32-bit binary string input to its decimal value
		double binaryToDecimal(string input);

		// Converts decimal input to its 32-bit binary string
		string decimalToBinary(double calculatedValue);

		// Converts to twos complement of a given binary string
		string computeTwosComplement(string bin);
		// Checks if input1 is less than input 2
		string lessThan(string input_1, string input_2);

};

#endif
