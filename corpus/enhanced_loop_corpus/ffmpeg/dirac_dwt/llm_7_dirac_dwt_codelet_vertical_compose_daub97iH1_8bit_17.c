#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *local_b1 = b1;
    int16_t *local_b0 = b0;
    int16_t *local_b2 = b2;
    int w = width;
    for (i = 0; i < w; i++) {
        int val = (113 * (local_b0[i] + (unsigned int)local_b2[i]) + 64) >> 7;
        local_b1[i] = (unsigned int)local_b1[i] - val;
    }
}
