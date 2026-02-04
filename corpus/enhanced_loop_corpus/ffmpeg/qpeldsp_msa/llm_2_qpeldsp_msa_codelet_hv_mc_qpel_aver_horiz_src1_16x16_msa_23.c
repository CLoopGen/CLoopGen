#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled copy (row-major, linearized)
    uint8_t *s = src;
    uint8_t *d = dst;
    for (loop_count = (height >> 2); loop_count--;) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];

        s += src_stride;
        d += dst_stride;
        
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];

        s += src_stride;
        d += dst_stride;
        
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];

        s += src_stride;
        d += dst_stride;
        
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];

        s += src_stride;
        d += dst_stride;
    }
}
