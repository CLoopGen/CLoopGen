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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *src_ptr = src + (x + radius) * src_step;
    uint8_t *prev_ptr = src + (x - radius - 1) * src_step;
    uint8_t *dst_ptr = dst + x * dst_step;

    for (; x < len - radius; x++) {
        sum += (*src_ptr - *prev_ptr) * inv;
        *dst_ptr = sum >> 16;
        src_ptr += src_step;
        prev_ptr += src_step;
        dst_ptr += dst_step;
    }
}
