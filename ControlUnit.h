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
        ControlUnit();
        int getValue(string control);
        void setInstruction(Instruction inst);
    private:
        Control myControls[10];

};

#endif
