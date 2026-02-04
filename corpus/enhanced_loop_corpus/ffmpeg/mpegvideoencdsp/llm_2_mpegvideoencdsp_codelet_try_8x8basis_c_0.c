#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t rem[64];
extern int16_t weight[64];
extern int16_t basis[64];
extern int scale;
extern int i;
extern unsigned int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 * 8; i++) {
    int idx = i;
    int b = rem[idx] + ((basis[idx] * scale + (1 << (16 - 6 - 1))) >> (16 - 6));
    int w = weight[idx];
    b >>= 6;
    ((void)0);
    sum += (w * b) * (w * b) >> 4;
}
}
