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
    for (i = 0; i < 4 * 8; i++) {
        int temp1 = basis[i] * scale;
        int temp2 = basis[i + 32] * scale;
        rem[i] += (temp1 + (1 << (16 - 6 - 1))) >> (16 - 6);
        rem[i + 32] += (temp2 + (1 << (16 - 6 - 1))) >> (16 - 6);
    }
}
