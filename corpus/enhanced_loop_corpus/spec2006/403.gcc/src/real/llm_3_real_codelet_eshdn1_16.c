#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array simulation using index remapping
    unsigned short *base_x = x - 2; // Adjust base to allow indexed access from offset
    for (i = 2; i < (6 + 3); i++) {
        unsigned short *current = &base_x[i]; // Simulate non-linear or indirect-like access pattern
        if (*current & 1)
            bits |= 1;
        *current >>= 1;
        if (bits & 2)
            *current |= 32768;
        bits <<= 1;
    }
}
