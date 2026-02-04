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
    {
        {
            int32_t offset = 0;
            for (int i = 0; i < 4; i++) {
                offset = i * src_stride;
                dst[i * dst_stride] = src[offset];
                dst[i * dst_stride + 1] = src[offset + 1];
            }
        }
        ;
        {
            uint8_t temp[8];
            for (int j = 0; j < 8; j++) {
                temp[j] = src[j] ^ 0xFF;
            }
            for (int j = 0; j < 8; j++) {
                dst[j] += temp[j];
            }
        }
        ;
    }
    ;
    src += (8 * src_stride);
    {
        {
            dst[0] = src[0] + src[1];
            dst[1] = src[2] + src[3];
        }
        ;
        {
            dst[2] = (src[4] > src[5]) ? src[4] : src[5];
            dst[3] = (src[6] > src[7]) ? src[6] : src[7];
        }
        ;
    }
    ;
    dst += (8 * dst_stride);
}
}
