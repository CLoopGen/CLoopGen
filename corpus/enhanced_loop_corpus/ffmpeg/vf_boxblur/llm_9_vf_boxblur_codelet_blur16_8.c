#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int dst_step;
extern  uint16_t *src;
extern int src_step;
extern int len;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; x < len; x += 2) {
        if (x < len) {
            sum += (src[(2 * len - radius - x - 1) * src_step] - src[(x - radius - 1) * src_step]) * inv;
            dst[x * dst_step] = sum >> 16;
        }
        if (x + 1 < len) {
            sum += (src[(2 * len - radius - x - 2) * src_step] - src[(x - radius) * src_step]) * inv;
            dst[(x + 1) * dst_step] = sum >> 16;
        }
    }
}
