#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, unrolled pattern)
    // We traverse only half the original range but with larger steps
    for (j = 100; j > 1; j -= 2) {
        x[j]     = x[j - 1];
        x[j - 1] = x[j - 2];
    }
    // Handle remaining element if needed
    if (j == 1) {
        x[j] = x[j - 1];
    }
}
