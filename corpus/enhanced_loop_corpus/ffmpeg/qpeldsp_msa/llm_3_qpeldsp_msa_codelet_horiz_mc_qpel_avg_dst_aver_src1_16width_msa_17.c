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
    int32_t vec_height = height >> 2;
    uint8_t **src_ptrs = (uint8_t**)alloca(vec_height * sizeof(uint8_t*));
    uint8_t **dst_ptrs = (uint8_t**)alloca(vec_height * sizeof(uint8_t*));

    for (int i = 0; i < vec_height; ++i) {
        src_ptrs[i] = src + (i * 4 * src_stride);
        dst_ptrs[i] = dst + (i * 4 * dst_stride);
    }

    for (loop_count = vec_height; loop_count--;) {
        uint8_t *s = src_ptrs[loop_count];
        uint8_t *d = dst_ptrs[loop_count];

        d[0] = s[0];
        d[dst_stride] = s[src_stride];
        d[2*dst_stride] = s[2*src_stride];
        d[3*dst_stride] = s[3*src_stride];

        s += (4 * src_stride);
        d += (4 * dst_stride);

        for (int offset = 1; offset < 4; ++offset) {
            d[-(4*dst_stride) + offset] = s[-(4*src_stride) + offset];
            d[-(3*dst_stride) + offset] = s[-(3*src_stride) + offset];
            d[-(2*dst_stride) + offset] = s[-(2*src_stride) + offset];
            d[-dst_stride + offset] = s[-src_stride + offset];
        }
    }
}
