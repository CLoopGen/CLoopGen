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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = 8 * 8 - 1; i >= 0; i--) {
        rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
    }
}
