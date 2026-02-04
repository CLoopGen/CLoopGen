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
    // Variant 2: Strided but unrolled by a factor of 2 for improved memory access pattern and reduced loop overhead
    int temp_sum = sum;
    int limit = radius - (radius % 2);  // Make it even for safe unrolling
    uint8_t *src_base = src + radius * src_step;
    uint8_t *dst_base = dst;

    // Unrolled loop with stride handling two iterations at once
    for (x = 0; x < limit; x += 2) {
        temp_sum += (src_base[x * src_step] - src_base[-x * src_step]) * inv;
        dst_base[x * dst_step] = temp_sum >> 16;

        temp_sum += (src_base[(x + 1) * src_step] - src_base[-(x + 1) * src_step]) * inv;
        dst_base[(x + 1) * dst_step] = temp_sum >> 16;
    }

    // Handle remaining iteration if radius is odd
    if (x <= radius) {
        temp_sum += (src_base[x * src_step] - src_base[-x * src_step]) * inv;
        dst_base[x * dst_step] = temp_sum >> 16;
    }
    sum = temp_sum;
}
