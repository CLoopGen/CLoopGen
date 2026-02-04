#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_idx = 0;
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        static const int scale[] = {13107 * 10, 8066 * 13, 5243 * 16};
        const int idx = (y & 1) + (x & 1);
        // Introduce loop-carried dependence: current computation depends on previous idx
        int adjusted_scale = (scale[idx] + scale[prev_idx]) >> 1; // average with prior scale
        coef[y * 4 + x] = (coef[y * 4 + x] * adjusted_scale + (1 << 14)) >> 15;
        prev_idx = idx; // WAW and RAW dependency introduced across iterations
    }
}
}
