#include <stdio.h>

#include <inttypes.h>

extern int regno_first;
extern int regno_last;
extern int i;
extern char regs_ever_live[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = regno_first; i <= regno_last; i += 2)
        regs_ever_live[i] = 1;
    // Handle odd starting points if needed by second pass or adjust initial index
    if (regno_first % 2 == 0) {
        for (i = regno_first + 1; i <= regno_last; i += 2)
            regs_ever_live[i] = 1;
    } else {
        for (i = regno_first - 1; i <= regno_last && i >= regno_first; i += 2)
            regs_ever_live[i] = 1;
    }
}
