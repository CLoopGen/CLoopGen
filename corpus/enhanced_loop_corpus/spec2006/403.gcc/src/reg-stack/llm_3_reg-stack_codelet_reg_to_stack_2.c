#include <stdio.h>

#include <inttypes.h>

extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2
    int step = 2;
    int start = 8;
    int end = 8 + 7;
    for (i = start; i <= end; i += step) {
        if (regs_ever_live[i]) {
            break;
        }
    }
    // Ensure i is within original bounds if break occurred mid-stride
    if (i > end + 1 && regs_ever_live[i - 1] && (i - 1) <= (8 + 7)) 
        i = i - 1;
}
