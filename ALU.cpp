//Class that implements Arithmetic and Logic unit
//Suvinay
//CMSC301
#include "ALU.h"
#include <math.h>
#include <bitset>

//Constructor
ALU::ALU() {}

// Returns "equal" if input1 and input2 are equivalent, "not_equal" otherwise
string ALU::compare(string input_1, string input_2) {
double input1_dec = binaryToDecimal(input_1);
double input2_dec = binaryToDecimal(input_2);
bool check = (input1_dec == input2_dec);
if (check) {
	return "equal";
}
return "not_equal";
}

	// Subtracts input2 from input1 (binary numbers represented as strings) and returns the result
string ALU::subtract(string input_1, string input_2) {

	double input1_dec = binaryToDecimal(input_1);
	double input2_dec = binaryToDecimal(input_2);
	double diff_dec = input1_dec - input2_dec;
	string diff_bin = decimalToBinary(diff_dec);

	return diff_bin;
}

// Adds input1 and input2 and returns the result
string ALU::add(string input_1, string input_2) {

double input1_dec = binaryToDecimal(input_1);
double input2_dec = binaryToDecimal(input_2);
double sum_dec = input1_dec + input2_dec;
string sum_bin = decimalToBinary(sum_dec);

return sum_bin;
}

	/// Return "00000000000000000000000000000001" if input1 is less than input2, else return"00000000000000000000000000000000"
string ALU::lessThan(string input_1, string input_2) {
	double input1_dec = binaryToDecimal(input_1);
	double input2_dec = binaryToDecimal(input_2);
	double diff_dec = input1_dec - input2_dec;
	// If difference is negative, input1 < input2, return 1
	if (diff_dec < 0) {
		return "00000000000000000000000000000001";
	}
	// Otherwise, return 0
	else {
		return "00000000000000000000000000000000";
	}
}

//conducts the ALU operation: addi, add,sub, beq, less than
void ALU::conductOperation() {

	// Add takes care of add and addi
	if (operation.compare("add") == 0) {
		result = add(input_1, input_2);
	}

	///Subtract takes care of sub
	else if (operation.compare("sub") == 0) {
		result = subtract(input_1, input_2);
	}

	// Compare -> beq
	else if (operation.compare("compare") == 0) {
		result = compare(input_1, input_2);
	}
	else if (operation.compare("lessThan") == 0) {
		result = lessThan(input_1, input_2);
	}

}

	// Converts 32-bit binary string input to its decimal value
double ALU::binaryToDecimal(string input) {

	double decimal = 0.0;
	int power = 0;

	// For each char in the given 32-bit input
	for(int i = input.length() - 1; i >= 0; i--) {

		if (input.at(i) == '1') {
			decimal += pow(2.0, power);
		}
		power++;
	}

	return decimal;
}

	// Converts decimal input to its 32-bit binary string
string ALU::decimalToBinary(double value) {
	bitset<32> bits = value;
	return bits.to_string();
}
