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
    int prev_dst_val = 0;
    for (x = 0; x <= radius; x++) {
        int src_diff = src[(radius + x) * src_step] - src[(radius - x) * src_step];
        sum += src_diff * inv;
        int shifted_sum = sum >> 16;
        dst[x * dst_step] = shifted_sum + prev_dst_val;
        prev_dst_val = shifted_sum;
    }
}
