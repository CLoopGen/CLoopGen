#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *a;
extern int32_t f[2][6];
extern int32_t tmp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration and direct index mapping
    for (i = 0; i < 5; i++) {
        int idx = 5 - i;
        tmp = f[0][i] + (unsigned int)f[1][i] + 4096;
        a[i] = tmp >> 13;
        tmp = f[0][i] - (unsigned int)f[1][i] + 4096;
        a[10 - i] = tmp >> 13;
    }
}
