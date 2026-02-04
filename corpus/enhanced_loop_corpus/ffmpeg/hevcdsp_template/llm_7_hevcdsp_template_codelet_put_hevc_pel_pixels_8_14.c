#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *dst_local = dst;
    uint8_t *src_local = src;
    int prev_val = 0; // Introduce loop-carried dependency (RAW)
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int16_t shifted = src_local[x] << (14 - 8);
            dst_local[x] = shifted + prev_val; // RAW: current iteration depends on previous `prev_val`
            prev_val = shifted & 0xFFFF;     // Update state — creates loop-carried dependence across x
        }
        prev_val = 0; // Reset per row to limit dependency scope
        src_local += srcstride;
        dst_local += 64;
    }
}
