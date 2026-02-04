#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int dst_step;
extern  uint16_t *src;
extern int src_step;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = sum;
    for (x = 0; x <= radius; x++) {
        int offset1 = (radius + x) * src_step;
        int offset2 = (radius - x) * src_step;
        temp_sum += (src[offset1] - src[offset2]) * inv;
        dst[x * dst_step] = temp_sum >> 16;
    }
    sum = temp_sum;
}
