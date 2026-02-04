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
    int local_sum = 0;
    int base_index = (x - radius - 1) * src_step;
    for (; x < len - radius; x++) {
        int read_index1 = (radius + x) * src_step;
        int read_index2 = base_index + x * src_step;
        int diff = src[read_index1] - src[read_index2];
        local_sum += diff * inv;
        dst[x * dst_step] = (sum + local_sum) >> 16;
    }
}
