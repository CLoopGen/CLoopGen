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
    int muv, minv, maxv;
    muv = minv = maxv = bp[0];
    for (int idx = 0; idx < 16; idx++) {
        int x = idx & 3;
        int y = idx >> 2;
        uint8_t val = bp[x * 4 + y * stride];
        muv += val;
        if (val < minv)
            minv = val;
        else if (val > maxv)
            maxv = val;
    }
    mu[ch] = (muv + 8) >> 4;
    min[ch] = minv;
    max[ch] = maxv;
}
}
