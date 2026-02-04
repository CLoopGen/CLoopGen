#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    for (x = 0; x < 8; x++) {
        static const int scale[] = {13107 * 20, 11428 * 18, 20972 * 32, 12222 * 19, 16777 * 25, 15481 * 24};
        static const int idxmap[] = {0, 3, 4, 3, 3, 1, 5, 1, 4, 5, 2, 5, 3, 1, 5, 1};
        const int index = (y & 3) * 4 + (x & 3);
        if (index >= 12) continue;
        const int idx = idxmap[index];
        coef[y * 8 + x] = ((int64_t)coef[y * 8 + x] * scale[idx] + (1 << 17)) >> 18;
    }
}
}
