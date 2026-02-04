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
    int j;
    for (i = 0; i < 8 * 4; i++) {
        for (j = 0; j < 2; j++) {
            int idx = i * 2 + j;
            rem[idx] = (rem[idx] + ((basis[idx] * scale * 3 + (1 << (16 - 6 - 1))) >> (16 - 6))) ^ 1;
        }
    }
}
