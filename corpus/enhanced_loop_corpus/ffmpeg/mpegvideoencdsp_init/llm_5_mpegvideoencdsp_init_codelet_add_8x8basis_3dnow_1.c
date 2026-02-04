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
    for (i = 0; i < 8 * 8; i++) {
        if (scale > 0) {
            rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
        } else {
            rem[i] -= (basis[i] * (-scale) + (1 << (16 - 6 - 1))) >> (16 - 6);
        }
    }
}
