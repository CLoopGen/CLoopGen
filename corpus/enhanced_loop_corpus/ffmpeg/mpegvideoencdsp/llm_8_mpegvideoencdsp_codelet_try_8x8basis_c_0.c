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
for (i = 0; i < 8 * 8; i += 2) {
    int b1 = rem[i] + ((basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6));
    int b2 = rem[i+1] + ((basis[i+1] * scale + (1 << (16 - 6 - 1))) >> (16 - 6));
    int w1 = weight[i];
    int w2 = weight[i+1];
    b1 >>= 6;
    b2 >>= 6;
    sum += (w1 * b1) * (w1 * b1) >> 4;
    sum += (w2 * b2) * (w2 * b2) >> 4;
}
}
