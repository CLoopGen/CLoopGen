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
    uint8_t accumulator = 0;
    uint8_t *s = src;
    uint8_t *d = dst;
    for (loop_count = (height >> 2); loop_count--;) {
        accumulator ^= s[0];
        d[0] = accumulator;

        accumulator ^= s[src_stride];
        d[dst_stride] = accumulator;

        accumulator ^= s[2 * src_stride];
        d[2 * dst_stride] = accumulator;

        accumulator ^= s[3 * src_stride];
        d[3 * dst_stride] = accumulator;

        s += 4 * src_stride;
        d += 4 * dst_stride;
    }
    dst = d; 
    src = s; 
}
