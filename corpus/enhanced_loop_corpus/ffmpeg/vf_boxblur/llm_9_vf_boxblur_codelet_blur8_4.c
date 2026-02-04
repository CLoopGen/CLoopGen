#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern  uint8_t *src;
extern int src_step;
extern int len;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int unroll_factor = 4;
    int remainder = len % unroll_factor;
    int limit = len - remainder;

    for (x = 0; x < limit; x += unroll_factor) {
        sum += (src[(2 * len - radius - x - 1) * src_step] - (x > 0 ? src[(x - radius - 1) * src_step] : 0)) * inv;
        dst[x * dst_step] = sum >> 16;

        sum += (src[(2 * len - radius - x - 2) * src_step] - src[(x - radius) * src_step]) * inv;
        dst[(x + 1) * dst_step] = sum >> 16;

        sum += (src[(2 * len - radius - x - 3) * src_step] - src[(x - radius + 1) * src_step]) * inv;
        dst[(x + 2) * dst_step] = sum >> 16;

        sum += (src[(2 * len - radius - x - 4) * src_step] - src[(x - radius + 2) * src_step]) * inv;
        dst[(x + 3) * dst_step] = sum >> 16;
    }

    for (; x < len; x++) {
        sum += (src[(2 * len - radius - x - 1) * src_step] - (x > 0 ? src[(x - radius - 1) * src_step] : 0)) * inv;
        dst[x * dst_step] = sum >> 16;
    }
}
