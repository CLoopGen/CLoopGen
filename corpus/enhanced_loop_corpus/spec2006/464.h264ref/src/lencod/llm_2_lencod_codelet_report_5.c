#include <stdio.h>

#include <inttypes.h>

extern int bit_use[5][2];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every element with stride of 1, but reverse iteration order)
    for (j = 4; j >= 0; j--) {
        bit_use[j][1] = 0;
    }
}
