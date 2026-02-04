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
        int offset = i << 1;
        rem[offset]     += ((basis[offset] * scale + (1 << (15))) >> 10);
        rem[offset + 1] += ((basis[offset + 1] * scale + (1 << (15))) >> 10);
    }
}
