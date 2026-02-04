#include <stdio.h>

#include <inttypes.h>

extern int regno_first;
extern int regno_last;
extern int i;
extern char regs_ever_live[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j = regno_first;
    for (i = 0; j <= regno_last; i++, j++) {
        regs_ever_live[j] = 1;
        // Eliminate direct loop-carried dependency by using independent index j
        // Data independence: each iteration accesses unique j, no inter-iteration dependency
    }
}
