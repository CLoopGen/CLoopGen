#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    // Unroll the loop to write two elements per iteration, maintaining total of 7 iterations (i from 2 to 8)
    for (i = 2; i < (6 + 3); i += 2) {
        *p++ = 0;
        if (i + 1 < (6 + 3)) {
            *p++ = 0;
        }
    }
}
