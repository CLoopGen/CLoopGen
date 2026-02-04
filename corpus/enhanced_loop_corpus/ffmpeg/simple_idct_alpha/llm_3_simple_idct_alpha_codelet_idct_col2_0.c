#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    for (i = 7; i >= 0; --i) {
        int a0 = col[i] + (1 << (20 - 1)) / 16383;
        a0 *= 16383;
        col[i] = a0 >> 20;
    }
}
