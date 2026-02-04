#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int mu[3];
extern int min[3];
extern int max[3];
extern int ch;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch < 3; ch++) {
    const uint8_t *bp = &block[ch];
    int muv = bp[0], minv = bp[0], maxv = bp[0];
    // Unroll inner loops partially to increase computational intensity
    for (y = 0; y < 4; y++) {
        int offset = y * stride;
        // Fully unroll x-loop
        uint8_t v0 = bp[0*4 + offset];
        uint8_t v1 = bp[1*4 + offset];
        uint8_t v2 = bp[2*4 + offset];
        uint8_t v3 = bp[3*4 + offset];

        muv += v0 + v1 + v2 + v3;

        if (v0 < minv) minv = v0; else if (v0 > maxv) maxv = v0;
        if (v1 < minv) minv = v1; else if (v1 > maxv) maxv = v1;
        if (v2 < minv) minv = v2; else if (v2 > maxv) maxv = v2;
        if (v3 < minv) minv = v3; else if (v3 > maxv) maxv = v3;
    }
    mu[ch] = (muv + 8) >> 4;
    min[ch] = minv;
    max[ch] = maxv;
}
}
