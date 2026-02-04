#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        static const int scale[] = {13107 * 10, 8066 * 13, 5243 * 16};
        const int idx = (y & 1) + (x & 1);
        int linear_idx = y * 4 + x;
        coef[linear_idx] = (coef[linear_idx] * scale[idx] + (1 << 14)) >> 15;
    }
}
}
