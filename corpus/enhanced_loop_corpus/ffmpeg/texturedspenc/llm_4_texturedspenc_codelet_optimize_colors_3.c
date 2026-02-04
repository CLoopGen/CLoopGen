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
for (y = 0; y < 4; ++y) {
    for (x = 0; x < 4; ++x) {
        int idx = x * 4 + stride * y;
        int r = block[idx + 0] - mu[0];
        int g = block[idx + 1] - mu[1];
        int b = block[idx + 2] - mu[2];
        if (!(r == 0 && g == 0 && b == 0)) {
            cov[0] += r * r;
            cov[1] += r * g;
            cov[2] += r * b;
            cov[3] += g * g;
            cov[4] += g * b;
            cov[5] += b * b;
        }
    }
}
}
