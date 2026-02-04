#include <stdio.h>

#include <inttypes.h>

extern int regno_first;
extern int regno_last;
extern int i;
extern char regs_ever_live[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with stride stepping and minimal operations
    for (i = regno_first; i <= regno_last; i += 2) {  // Half the iterations by stepping in increments of 2
        regs_ever_live[i] = 1;
        if (i + 1 <= regno_last) {
            regs_ever_live[i + 1] = 1;  // Unrolled one extra assignment per iteration
        }
    }
}
