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
int i1, i2;
for (i1 = 0; i1 < 8; i1++)
    for (i2 = 0; i2 < 8; i2++) {
        i = i1 * 8 + i2;
        rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
    }
}
