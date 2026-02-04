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
    // Introduce temporary accumulators and separate reduction passes to break false dependencies
    int sum = bp[0];
    int local_min = bp[0];
    int local_max = bp[0];
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int idx = x * 4 + y * stride;
            uint8_t val = bp[idx];
            sum += val;
            if (val < local_min) local_min = val;
            if (val > local_max) local_max = val;
        }
    }
    muv = sum;
    minv = local_min;
    maxv = local_max;
    mu[ch] = (muv + 8) >> 4;
    min[ch] = minv;
    max[ch] = maxv;
}
}
