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
for (cnt = (height / 8); cnt--;) {
    int32_t offset;
    for (int row = 0; row < 8; ++row) {
        offset = row * src_stride;
        for (int col = 0; col < 8; ++col) {
            dst[col * dst_stride + row] = src[offset + col];
        }
    }

    src += 8 * src_stride;
    dst += 8 * dst_stride;
}
}
