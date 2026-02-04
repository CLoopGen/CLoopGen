#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    for (i = 0; i < 8; i += 2) {
        int a0 = col[i] + (1 << (20 - 1)) / 16383;
        a0 *= 16383;
        col[i] = a0 >> 20;
    }
}
