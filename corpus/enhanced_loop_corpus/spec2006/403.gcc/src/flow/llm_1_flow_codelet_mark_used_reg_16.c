#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern unsigned int regno_first;
extern unsigned int regno_last;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (regno_first <= regno_last)
        for (i = regno_first; i <= regno_last; ++i)
            for (unsigned int k = 0; k < 1; ++k)
                regs_ever_live[i] = 1;
}
