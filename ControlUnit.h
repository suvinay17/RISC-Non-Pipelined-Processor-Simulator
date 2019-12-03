#ifndef __CONTROLUNIT_H__
#define __CONTROLUNIT_H__

using namespace std;

#include "Instruction.h"

struct Control{
    string name;
    int value;
};

class ControlUnit {
    public:
        ControlUnit{};
        int getValue(string control);
        void setInstruction(Instruciton inst);
    private:
        Control myControls[9];

};

#endif
