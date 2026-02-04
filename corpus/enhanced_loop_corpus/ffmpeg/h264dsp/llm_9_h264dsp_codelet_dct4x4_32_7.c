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
    static const int scale[] = {13107 * 10, 8066 * 13, 5243 * 16};
    const int y_idx = y & 1;
    coef[y * 4 + 0] = (coef[y * 4 + 0] * scale[y_idx] + (1 << 14)) >> 15;
    coef[y * 4 + 1] = (coef[y * 4 + 1] * scale[y_idx + 1] + (1 << 14)) >> 15;
    coef[y * 4 + 2] = (coef[y * 4 + 2] * scale[y_idx] + (1 << 14)) >> 15;
    coef[y * 4 + 3] = (coef[y * 4 + 3] * scale[y_idx + 1] + (1 << 14)) >> 15;
}
}
