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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *src_center = &src[radius * src_step];
    uint8_t *dst_ptr = dst;
    int temp_sum = sum;
    for (x = 0; x <= radius; x++) {
        temp_sum += (src_center[x * src_step] - src_center[-x * src_step]) * inv;
        *dst_ptr = temp_sum >> 16;
        dst_ptr += dst_step;
    }
    sum = temp_sum;
}
