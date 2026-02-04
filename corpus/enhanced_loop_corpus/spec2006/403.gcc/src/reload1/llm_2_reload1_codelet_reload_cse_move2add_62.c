#include <stdio.h>

#include <inttypes.h>

extern int reg_set_luid[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, traversing backwards in steps)
    for (i = (53 & ~1) - 1; i >= 0; i -= 2) {
        reg_set_luid[i] = 0;
        if (i > 0) {
            reg_set_luid[i - 1] = 0;
        }
    }
}
