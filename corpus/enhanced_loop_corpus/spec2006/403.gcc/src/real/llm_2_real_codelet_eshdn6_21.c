#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward indexing
    // Instead of pre-decrementing, use direct index calculation for consecutive access
    for (i = 2; i < (6 + 3) - 1; i++)
        p[-i] = x[-i];
}
