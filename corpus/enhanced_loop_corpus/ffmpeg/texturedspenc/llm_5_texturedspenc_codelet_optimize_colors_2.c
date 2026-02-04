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
    int val;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            val = bp[x * 4 + y * stride];
            muv += val;
            minv = (val < minv) ? val : minv;
            maxv = (val > maxv) ? val : maxv;
        }
    }
    mu[ch] = (muv + 8) >> 4;
    min[ch] = minv;
    max[ch] = maxv;
}
}
