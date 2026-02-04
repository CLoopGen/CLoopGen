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
    for (i = 0; i < 8; i++) {
        for (x86_reg j = 0; j < 8; j++) {
            x86_reg idx = i * 8 + j;
            rem[idx] += (basis[idx] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
        }
    }
}
