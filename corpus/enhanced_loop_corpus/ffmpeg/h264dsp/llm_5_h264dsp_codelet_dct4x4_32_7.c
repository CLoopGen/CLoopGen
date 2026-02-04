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
            // Introduce control dependency: skip center elements based on position
            if ((y == 1 || y == 2) && (x == 1 || x == 2)) {
                continue;
            }
            coef[y * 4 + x] = (coef[y * 4 + x] * scale[idx] + (1 << 14)) >> 15;
        }
    }
}
