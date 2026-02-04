#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of accessing tmp with variable offsets, precompute a sliding window
    // and access elements consecutively in a transformed order.
    for (y = 0; y < h; y++) {
        uint8_t *tmp_offset = tmp;
        int val[4];
        // Precompute the weighted sum using reordered array accesses for better locality
        for (x = 0; x < 4; x++) {
            int sum = 0;
            sum += filter[2] * tmp_offset[x + 0];
            sum -= filter[1] * tmp_offset[x - 4];
            sum += filter[0] * tmp_offset[x - 8];
            sum += filter[3] * tmp_offset[x + 4];
            sum -= filter[4] * tmp_offset[x + 8];
            sum += filter[5] * tmp_offset[x + 12];
            val[x] = (sum + 64) >> 7;
        }
        for (x = 0; x < 4; x++) {
            dst[x] = cm[val[x]];
        }
        dst += dststride;
        tmp += 4;
    }
}
