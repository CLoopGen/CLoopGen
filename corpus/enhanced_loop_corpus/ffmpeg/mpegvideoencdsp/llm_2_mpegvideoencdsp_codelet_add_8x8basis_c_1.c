#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t rem[64];
extern int16_t basis[64];
extern int scale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 8 * 8; i += 2) {
        rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
        if (i + 1 < 8 * 8) {
            rem[i + 1] += (basis[i + 1] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
        }
    }
}
