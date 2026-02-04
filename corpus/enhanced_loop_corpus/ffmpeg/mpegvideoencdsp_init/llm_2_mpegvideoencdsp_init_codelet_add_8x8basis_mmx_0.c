#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int x86_reg;

extern int16_t rem[64];
extern int16_t basis[64];
extern int scale;
extern x86_reg i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element first, then the odd indices)
    for (i = 0; i < 8 * 8; i += 2) {
        rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
    }
    for (i = 1; i < 8 * 8; i += 2) {
        rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
    }
}
