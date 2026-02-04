#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    int start = 8;
    int end = 8 + 7;
    for (i = end; i >= start; i--) {
        if (regs_ever_live[i])
            break;
    }
}
