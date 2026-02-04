#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern unsigned int regno_first;
extern unsigned int regno_last;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int step = 2;
    for (i = regno_first; i <= regno_last; i += step) {
        regs_ever_live[i] = 1;
        if (i + 1 <= regno_last)
            regs_ever_live[i + 1] = 1;
    }
}
