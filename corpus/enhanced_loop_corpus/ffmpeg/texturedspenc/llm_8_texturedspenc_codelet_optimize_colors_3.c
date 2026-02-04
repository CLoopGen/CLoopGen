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
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x += 2) {
        int r1 = block[x * 4 + stride * y + 0] - mu[0];
        int g1 = block[x * 4 + stride * y + 1] - mu[1];
        int b1 = block[x * 4 + stride * y + 2] - mu[2];
        cov[0] += r1 * r1;
        cov[1] += r1 * g1;
        cov[2] += r1 * b1;
        cov[3] += g1 * g1;
        cov[4] += g1 * b1;
        cov[5] += b1 * b1;

        if (x + 1 < 4) {
            int r2 = block[(x+1) * 4 + stride * y + 0] - mu[0];
            int g2 = block[(x+1) * 4 + stride * y + 1] - mu[1];
            int b2 = block[(x+1) * 4 + stride * y + 2] - mu[2];
            cov[0] += r2 * r2;
            cov[1] += r2 * g2;
            cov[2] += r2 * b2;
            cov[3] += g2 * g2;
            cov[4] += g2 * b2;
            cov[5] += b2 * b2;
        }
    }
}
}
