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
    for (int i = 0; i < 8; ++i) {
        uint8_t *src_row = src + i * src_stride;
        uint8_t *dst_row = dst + i * dst_stride;
        for (int j = 0; j < 8; ++j) {
            dst_row[j] = src_row[j];
        }
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
