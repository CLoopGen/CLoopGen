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
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            muv += bp[x * 4 + y * stride];
            if (bp[x * 4 + y * stride] < minv)
                minv = bp[x * 4 + y * stride];
            else if (bp[x * 4 + y * stride] > maxv)
                maxv = bp[x * 4 + y * stride];
        }
    }
    mu[ch] = (muv + 8) >> 4;
    min[ch] = minv;
    max[ch] = maxv;
}

}
