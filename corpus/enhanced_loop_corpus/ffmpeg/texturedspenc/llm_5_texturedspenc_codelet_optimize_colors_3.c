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
    for (x = 0; x < 4; x++) {
        int offset = x * 4 + stride * y;
        int r = block[offset + 0] - mu[0];
        int g = block[offset + 1] - mu[1];
        int b = block[offset + 2] - mu[2];

        // Introduce control dependency: skip low-variance updates
        if (r > -2 && r < 2) continue;
        cov[0] += r * r;

        if (g > -2 && g < 2) continue;
        cov[3] += g * g;

        if (b > -2 && b < 2) continue;
        cov[5] += b * b;

        // Cross terms only when all components are significant
        cov[1] += r * g;
        cov[2] += r * b;
        cov[4] += g * b;
    }
}
}
