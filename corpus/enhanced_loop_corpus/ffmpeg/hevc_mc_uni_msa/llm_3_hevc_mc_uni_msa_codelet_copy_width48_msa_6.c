#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 2); cnt--;) {
    // Change to strided memory access: process every second row, then fill in gaps
    // Simulate a non-unit stride over effective output/input with unrolled step

    int32_t eff_src_stride = 2 * src_stride;
    int32_t eff_dst_stride = 2 * dst_stride;

    uint8_t *s0 = src;
    uint8_t *s1 = src + src_stride;
    uint8_t *d0 = dst;
    uint8_t *d1 = dst + dst_stride;

    for (int k = 0; k < 2; ++k) {
        for (int n = 0; n < 4; ++n) {
            d0[n] = s0[n];
            d1[n] = s1[n];
        }
        s0 += eff_src_stride;
        s1 += eff_src_stride;
        d0 += eff_dst_stride;
        d1 += eff_dst_stride;
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
