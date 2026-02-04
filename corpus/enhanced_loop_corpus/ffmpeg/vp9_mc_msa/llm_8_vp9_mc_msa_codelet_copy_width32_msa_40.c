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
for (cnt = (height >> 2); cnt--;) {
    for (int i = 0; i < 4; ++i) {
        {
            {
                dst[i * dst_stride + 0] = src[i * src_stride + 0];
                dst[i * dst_stride + 1] = src[i * src_stride + 1];
                dst[i * dst_stride + 2] = src[i * src_stride + 2];
                dst[i * dst_stride + 3] = src[i * src_stride + 3];
            }
            ;
            {
                dst[i * dst_stride + 4] = src[i * src_stride + 4];
                dst[i * dst_stride + 5] = src[i * src_stride + 5];
                dst[i * dst_stride + 6] = src[i * src_stride + 6];
                dst[i * dst_stride + 7] = src[i * src_stride + 7];
            }
            ;
        }
    }
    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
