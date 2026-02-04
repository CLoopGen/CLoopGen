#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    uint8_t val0, val1, val2, val3;
    val0 = src[0 * src_stride];
    val1 = src[1 * src_stride];
    val2 = src[2 * src_stride];
    val3 = src[3 * src_stride];

    dst[0 * dst_stride] = val0;
    dst[1 * dst_stride] = val1;
    dst[2 * dst_stride] = val2;
    dst[3 * dst_stride] = val3;

    uint8_t val4, val5, val6, val7;
    val4 = src[4 * src_stride];
    val5 = src[5 * src_stride];
    val6 = src[6 * src_stride];
    val7 = src[7 * src_stride];

    dst[0 * dst_stride] ^= val4; 
    dst[1 * dst_stride] ^= val5;
    dst[2 * dst_stride] ^= val6;
    dst[3 * dst_stride] ^= val7;

    src += (8 * src_stride);

    dst += (4 * dst_stride);

    dst[0 * dst_stride] = val0 ^ val4;
    dst[1 * dst_stride] = val1 ^ val5;
    dst[2 * dst_stride] = val2 ^ val6;
    dst[3 * dst_stride] = val3 ^ val7;

    dst += (4 * dst_stride);
}
}
