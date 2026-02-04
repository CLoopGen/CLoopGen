#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;
extern int min_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *src_ptr = src;
    uint8_t *dst_ptr = dst;
    int prev_r = r, prev_g = g, prev_b = b, prev_a = a;
    for (i = 0; i < min_width; i++) {
        const int rt = src_ptr[2];
        const int gt = src_ptr[1];
        const int bt = src_ptr[0];
        const int at = src_ptr[3];
        dst_ptr[2] = rt - prev_r;
        dst_ptr[1] = gt - prev_g;
        dst_ptr[0] = bt - prev_b;
        dst_ptr[3] = at - prev_a;
        prev_r = rt;
        prev_g = gt;
        prev_b = bt;
        prev_a = at;
        src_ptr += 4;
        dst_ptr += 4;
    }
}
