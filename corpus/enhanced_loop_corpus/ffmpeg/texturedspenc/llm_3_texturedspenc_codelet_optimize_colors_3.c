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
    // Variant 2: Strided access with separate loops for each color channel to create distinct access patterns
    // Accumulate contributions from each pixel by iterating per channel in a strided manner
    cov[0] = cov[1] = cov[2] = cov[3] = cov[4] = cov[5] = 0; // Reset cov if needed

    // Process R channel (stride * 4 + 4 step between same-channel pixels)
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int r = block[x * 4 + stride * y + 0] - mu[0];
            int g = block[x * 4 + stride * y + 1] - mu[1];
            int b = block[x * 4 + stride * y + 2] - mu[2];
            cov[0] += r * r;
            cov[1] += r * g;
            cov[2] += r * b;
            cov[3] += g * g;
            cov[4] += g * b;
            cov[5] += b * b;
        }
    }
}
