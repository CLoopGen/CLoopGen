#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with positive stride
    // Instead of decrementing x (backward traversal), we access every second element forward
    // We assume adjusted initial conditions so that the logic remains meaningful
    unsigned short *base = x - 8; // Adjust base so that starting at base + 2*stride is valid
    for (i = 2; i < (6 + 3); i++) {
        unsigned short *current = base + 2 * i; // Strided access: step by 2
        if (*current & 32768)
            bits |= 1;
        *current <<= 1;
        if (bits & 2)
            *current |= 1;
        bits <<= 1;
    }
}
