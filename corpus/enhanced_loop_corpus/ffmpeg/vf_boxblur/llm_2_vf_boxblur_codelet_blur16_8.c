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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *src_ptr = src + (2 * len - radius - 1) * src_step;
    uint16_t *src_neg = src + (-radius - 1) * src_step;
    uint16_t *dst_ptr = dst;
    for (; x < len; x++) {
        sum += ((*src_ptr - *src_neg) * inv);
        *dst_ptr = sum >> 16;
        src_ptr -= src_step;     // Traverse src backwards consecutively
        src_neg += src_step;     // Move forward in negative index equivalent
        dst_ptr += dst_step;
    }
}
