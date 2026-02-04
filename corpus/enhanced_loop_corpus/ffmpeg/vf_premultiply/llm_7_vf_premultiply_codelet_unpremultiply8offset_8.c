#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int offset;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    // Eliminate loop-carried dependencies by precomputing values not dependent on previous iterations
    // Introduce local accumulators to break false dependencies
    uint8_t base_offset = offset > 0 ? offset : 0;
    uint8_t clamp_low, scaled_val;
    for (x = 0; x < w; x++) {
        // Remove repeated computation by factoring clamping
        clamp_low = (msrc[x] > offset) ? (msrc[x] - offset) : 0;

        if (asrc[x] > 0 && asrc[x] < 255) {
            scaled_val = clamp_low * 255 / asrc[x];
            dst[x] = (scaled_val + base_offset) < 256 ? (scaled_val + base_offset) : 255;
        } else {
            dst[x] = msrc[x];
        }
    }
    // Update pointers after full row processing (same as original, no loop-carried dep across rows)
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
