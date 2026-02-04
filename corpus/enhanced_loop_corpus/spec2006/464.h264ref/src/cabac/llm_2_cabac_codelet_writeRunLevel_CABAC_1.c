#include <stdio.h>

#include <inttypes.h>

extern int coeff[64];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (int i = pos; i < 64; i += 2) {
        coeff[i] = 0;
        if (i + 1 < 64) {
            coeff[i + 1] = 0;
        }
    }
    pos = 64; // Ensure pos reaches 64 to satisfy original termination condition
}
