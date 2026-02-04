#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_idx = 0;
for (y = 0; y < 8; y++) {
    for (x = 0; x < 8; x++) {
        static const int scale[] = {13107 * 20, 11428 * 18, 20972 * 32, 12222 * 19, 16777 * 25, 15481 * 24};
        static const int idxmap[] = {0, 3, 4, 3, 3, 1, 5, 1, 4, 5, 2, 5, 3, 1, 5, 1};
        const int idx = idxmap[(y & 3) * 4 + (x & 3)];
        // Introduce loop-carried dependency: scale value depends on previous iteration's index
        int adjusted_scale = scale[idx] + (prev_idx & 1 ? 100 : -100);
        coef[y * 8 + x] = ((int64_t)coef[y * 8 + x] * adjusted_scale + (1 << 17)) >> 18;
        prev_idx = idx; // WAW and RAW dependency introduced across iterations
    }
}
}
