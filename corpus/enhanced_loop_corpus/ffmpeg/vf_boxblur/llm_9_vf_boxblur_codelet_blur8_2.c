#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern  uint8_t *src;
extern int src_step;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count and increase per-iteration arithmetic density
    for (x = 0; x <= radius; x += 2) {
        int idx1 = (radius + x) * src_step;
        int idx2 = (radius - x) * src_step;
        int diff1 = src[idx1] - src[idx2];
        sum += diff1 * inv;

        // Process two elements per iteration if possible
        if (x + 1 <= radius) {
            int idx3 = (radius + x + 1) * src_step;
            int idx4 = (radius - x - 1) * src_step;
            int diff2 = src[idx3] - src[idx4];
            sum += diff2 * inv;
            dst[(x + 1) * dst_step] = sum >> 16;
        }

        dst[x * dst_step] = sum >> 16;
    }
}
