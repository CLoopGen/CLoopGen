#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern unsigned int regno_first;
extern unsigned int regno_last;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = regno_first; i <= regno_last; ++i) {
        if (i % 2 == 0)
            regs_ever_live[i] = 1;
        else
            regs_ever_live[i] = 0;
    }
}
