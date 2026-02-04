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
for (int block = 0; block < 8; block += 2) {
    for (int offset = 0; offset < 8; offset++) {
        for (int inner = 0; inner < 2; inner++) {
            int i = block * 8 + inner * 8 + offset;
            if (i >= 64) continue;
            int b = rem[i] + ((basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6));
            int w = weight[i];
            b >>= 6;
            ((void)0);
            sum += (w * b) * (w * b) >> 4;
        }
    }
}
}
