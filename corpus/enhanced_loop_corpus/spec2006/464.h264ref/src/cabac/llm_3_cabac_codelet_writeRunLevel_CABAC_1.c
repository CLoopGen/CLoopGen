#include <stdio.h>

#include <inttypes.h>

extern int coeff[64];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from 63 down to pos
    for (int i = 63; i >= pos; i--) {
        coeff[i] = 0;
    }
    pos = 64; // Update pos to reflect completion
}
