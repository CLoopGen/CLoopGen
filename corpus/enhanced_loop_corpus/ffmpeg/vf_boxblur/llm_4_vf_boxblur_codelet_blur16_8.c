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
    if (len <= 0) return;
    for (; x < len; x++) {
        int idx1 = (2 * len - radius - x - 1) * src_step;
        int idx2 = (x - radius - 1) * src_step;
        uint16_t val1 = src[idx1];
        uint16_t val2 = 0;
        if (x > radius) {
            val2 = src[idx2];
        }
        sum += (val1 - val2) * inv;
        dst[x * dst_step] = sum >> 16;
    }
}
