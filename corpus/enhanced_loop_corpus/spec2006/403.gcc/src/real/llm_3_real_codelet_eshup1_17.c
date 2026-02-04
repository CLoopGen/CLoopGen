#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an auxiliary lookup table to access x in a non-sequential, indirect manner
    static int offsets[] = {0, -2, 1, -4, 3, -1, 2, -3, 4}; // Example offset pattern
    for (i = 2; i < (6 + 3); i++) {
        unsigned short *p = x + offsets[i]; // Indirect addressing
        if (*p & 32768)
            bits |= 1;
        *p <<= 1;
        if (bits & 2)
            *p |= 1;
        bits <<= 1;
    }
}
