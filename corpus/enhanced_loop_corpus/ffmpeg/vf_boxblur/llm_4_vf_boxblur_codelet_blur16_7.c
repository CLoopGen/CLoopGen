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
    for (; x < len - radius; x++) {
        int index1 = (radius + x) * src_step;
        int index2 = (x - radius - 1) * src_step;
        sum += (src[index1] - src[index2]) * inv;
        if (sum > 0) {
            dst[x * dst_step] = sum >> 16;
        }
    }
}
