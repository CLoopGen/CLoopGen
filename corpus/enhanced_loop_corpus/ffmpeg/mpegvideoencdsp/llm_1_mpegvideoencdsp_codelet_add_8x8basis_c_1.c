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
int outer_i;
for (outer_i = 0; outer_i < 4; outer_i++) {
    int base = outer_i * 16;
    for (i = 0; i < 16; i++) {
        int idx = base + i;
        rem[idx] += (basis[idx] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
    }
}
}
