#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 2; i < (6 + 3) - 1; i++)
        *p++ = x[i - 2];  // Base index adjusted to maintain alignment with original logic
}
