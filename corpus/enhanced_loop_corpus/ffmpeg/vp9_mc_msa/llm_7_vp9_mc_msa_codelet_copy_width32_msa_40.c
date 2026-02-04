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
for (cnt = (height >> 3); cnt--;) {
    uint8_t *s_ptr = src;
    uint8_t *d_ptr = dst;
    uint8_t val_accum = 0;
    for (int row = 0; row < 8; row++) {
        uint8_t row_val = s_ptr[row * src_stride];
        val_accum ^= row_val;
        d_ptr[row * dst_stride] = val_accum;
    }
    d_ptr[1] = val_accum;
    for (int row = 0; row < 8; row++) {
        d_ptr[row * dst_stride + 1] = s_ptr[row * src_stride] + val_accum;
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
