/*This class implements Multiplexor
Written by Suvinay
For CMSC301
Multiplexor uses three member variables controlInput, firstInput and secondInput.
The controlInput is set by the control unit and the inputs are sent to each
multiplexor in the datapath.  Depending on the ControlInput set by the control,
the multiplexor sends the value to continue in the datapath.
*/
#ifndef __MULTIPLEXOR_CPP__
#define __MULTIPLEXOR_CPP__

#include "Multiplexor.h"
#include <iostream>

//Constructor
Multiplexor::Multiplexor(){}

//Deconstructor
Multiplexor::~Multiplexor(){}

//Returns signal for testing
int Multiplexor::getControlInput()
{
    return controlInput;
}

//used by the Control Unit, which sends true or false based on whether or not the mux is needed.
void Multiplexor::setControlInput(int controlInput)
{
    this->controlInput = controlInput;

}

//Sets input one in the multiplexor, return for test
std::string Multiplexor::setFirstInput(std::string firstInput)
{
	this->firstInput = firstInput;
	return this->firstInput;
}

//Sets input at 1 that coincides with 1 on the picture

std::string Multiplexor::setSecondInput(std::string secondInput)
{
	this->secondInput = secondInput;
	return this->secondInput;
}


//calls mux and returns the result chosen
std::string Multiplexor::mux()
{
	if(this->controlInput == 0)
	{
		return this->firstInput;
	}
	else
	{
		return this->secondInput;
	}

}

#endif
