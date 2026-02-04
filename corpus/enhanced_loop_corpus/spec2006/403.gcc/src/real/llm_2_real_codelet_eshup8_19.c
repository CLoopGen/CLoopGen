#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short newbyt;
extern unsigned short oldbyt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (forward traversal with pointer arithmetic)
    unsigned short temp_oldbyt = oldbyt;
    unsigned short *ptr = x - 6; // Point to the start of the region we'll access
    for (i = 2; i < (6 + 3); i++) {
        unsigned short temp_newbyt = ptr[i] >> 8;
        ptr[i] <<= 8;
        ptr[i] |= temp_oldbyt;
        temp_oldbyt = temp_newbyt;
    }
    oldbyt = temp_oldbyt;
}
