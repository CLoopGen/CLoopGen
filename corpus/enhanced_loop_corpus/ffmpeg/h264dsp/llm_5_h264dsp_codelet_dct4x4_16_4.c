#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; ++y) {
    for (x = 0; x < 4; ++x) {
        static const int scale[] = {13107 * 10, 8066 * 13, 5243 * 16};
        const int idx = (y & 1) + (x & 1);
        if ((y + x) % 2 == 0) {
            coef[y * 4 + x] = (coef[y * 4 + x] * scale[idx] + (1 << 14)) >> 15;
        } else {
            continue;
        }
    }
}
}
