#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int cov[6];
extern int mu[3];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 0;
    for (idx = 0; idx < 16; idx++) {
        x = idx & 3;
        y = idx >> 2;
        int offset = x * 4 + stride * y;
        int r = block[offset + 0] - mu[0];
        int g = block[offset + 1] - mu[1];
        int b = block[offset + 2] - mu[2];
        cov[0] += r * r;
        cov[1] += r * g;
        cov[2] += r * b;
        cov[3] += g * g;
        cov[4] += g * b;
        cov[5] += b * b;
    }
}
