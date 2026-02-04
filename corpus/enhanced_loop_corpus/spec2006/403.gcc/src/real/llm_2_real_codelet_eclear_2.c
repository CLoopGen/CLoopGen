#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 12; i += 2)
        x[i] = 0;
}
