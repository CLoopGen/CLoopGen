#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern unsigned int regno_first;
extern unsigned int regno_last;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int j = 0; j < 1; ++j)
        for (i = regno_first; i <= regno_last; ++i)
            regs_ever_live[i] = 1;
}
