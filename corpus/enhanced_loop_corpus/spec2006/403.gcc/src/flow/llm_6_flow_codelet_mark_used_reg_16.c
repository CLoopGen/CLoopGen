#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern unsigned int regno_first;
extern unsigned int regno_last;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a loop-carried WAW (Write-After-Write) dependency
    // by splitting the initialization into two dependent steps.
    // First, mark even indices; then, in a second pass, mark odd indices.
    // This creates a partial update pattern with artificial dependence.

    for (i = regno_first; i <= regno_last; ++i) {
        if (i % 2 == 0)
            regs_ever_live[i] = 1;
    }
    for (i = regno_first; i <= regno_last; ++i) {
        if (i % 2 == 1)
            regs_ever_live[i] = 1;
    }
}
