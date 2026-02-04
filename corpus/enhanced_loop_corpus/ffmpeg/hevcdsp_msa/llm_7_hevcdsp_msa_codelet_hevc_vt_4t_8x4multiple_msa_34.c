#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Remove loop-carried data dependencies by unrolling and reordering memory operations
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t *s0 = src;
    uint8_t *s1 = src + src_stride;
    uint8_t *s2 = src + 2 * src_stride;
    uint8_t *s3 = src + 3 * src_stride;

    int16_t *d0 = dst;
    int16_t *d1 = dst + dst_stride;
    int16_t *d2 = dst + 2 * dst_stride;
    int16_t *d3 = dst + 3 * dst_stride;

    // Fully independent assignments — eliminate RAW/WAR/WAW within iteration
    *d0 = (int16_t)(*s0);
    *d1 = (int16_t)(*s1);
    *d2 = (int16_t)(*s2);
    *d3 = (int16_t)(*s3);

    // Pointer update without interference
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
