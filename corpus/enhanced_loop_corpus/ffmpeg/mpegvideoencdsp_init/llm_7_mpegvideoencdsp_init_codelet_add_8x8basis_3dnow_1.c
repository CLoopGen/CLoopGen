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
    int16_t acc = 0;
    for (i = 0; i < 8 * 8; i++) {
        acc += basis[i] * scale;
        rem[i] += (acc + (1 << (16 - 6 - 1))) >> (16 - 6);
        acc &= 0xFFFF; // Prevent overflow from dominating behavior
    }
}
