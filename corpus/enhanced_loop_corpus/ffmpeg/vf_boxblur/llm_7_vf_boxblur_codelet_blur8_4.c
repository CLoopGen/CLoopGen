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
    int local_sum = sum;
    int prev_offset = (x - radius - 1) * src_step;
    for (; x < len; x++) {
        int forward_index = (2 * len - radius - x - 1) * src_step;
        int current_diff = src[forward_index] - (x > 0 ? src[prev_offset] : 0);
        local_sum += current_diff * inv;
        dst[x * dst_step] = local_sum >> 16;
        prev_offset = (x - radius - 1) * src_step;
    }
    sum = local_sum;
}
