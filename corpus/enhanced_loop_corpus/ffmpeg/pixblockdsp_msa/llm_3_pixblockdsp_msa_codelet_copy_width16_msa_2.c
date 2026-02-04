#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height / 12); cnt--;) {
    int32_t row;
    uint8_t *s_ptr, *d_ptr;

    for (row = 0; row < 12; ++row) {
        s_ptr = src + (row * src_stride);
        d_ptr = dst + (row * dst_stride);

        d_ptr[0] = s_ptr[0];
        d_ptr[1] = s_ptr[1];
        d_ptr[2] = s_ptr[2];
        d_ptr[3] = s_ptr[3];
        d_ptr[4] = s_ptr[4];
        d_ptr[5] = s_ptr[5];
        d_ptr[6] = s_ptr[6];
        d_ptr[7] = s_ptr[7];
    }

    src += (12 * src_stride);
    dst += (12 * dst_stride);
}
}
