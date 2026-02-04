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
    uint8_t *s = src;
    uint8_t *d = dst;
    int32_t s_stride = src_stride;
    int32_t d_stride = dst_stride;
    int32_t h = height;
    uint8_t count;

    for (count = (h >> 2); count > 0; count--) {
        d[0] = s[0];
        d[s_stride] = s[s_stride];
        d[2 * s_stride] = s[2 * s_stride];
        d[3 * s_stride] = s[3 * s_stride];

        s += (4 * s_stride);
        d += (4 * d_stride);
    }

    src = s;
    dst = d;
}
