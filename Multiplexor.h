// .h file for Multiplexor
//Suvinay Bothra
//CMSC301
#ifndef __MULTIPLEXOR_H__
#define __MULTIPLEXOR_H__

#include <string>

class Multiplexor
{
	protected:
    std::string firstInput;
    std::string secondInput;
    //0 or 1, depending on the value in the picture of the processor.
    int controlInput;

    public:
			//Constructor
        Multiplexor();
				//Deconstructor
        ~Multiplexor();

        std::string setFirstInput(std::string firstInput);

        std::string setSecondInput(std::string secondInput);

        std::string mux();

        void setControlInput(int controlInput);

        int getControlInput();

};

#endif
