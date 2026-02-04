#include <stdio.h>

#include <inttypes.h>

extern int numlines_s[63];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; numlines_s[i] >= 0; i += 2)
        if (i + 1 >= 63 || numlines_s[i + 1] < 0) break;
}
