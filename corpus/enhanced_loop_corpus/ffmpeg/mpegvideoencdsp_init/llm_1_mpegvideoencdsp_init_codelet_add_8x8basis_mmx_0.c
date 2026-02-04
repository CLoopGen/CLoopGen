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
    for (x86_reg block = 0; block < 8; block++) {
        for (x86_reg offset = 0; offset < 8; offset++) {
            x86_reg i = block * 8 + offset;
            rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
        }
    }
}
