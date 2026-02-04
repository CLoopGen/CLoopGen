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
for (cnt = (height >> 1); cnt--;) {
    {
        {
            uint8_t val = src[0];
            dst[0] = val << 1;
            dst[1] = val >> 1;
        }
        ;
        {
            dst[2] = src[1] + 10;
            dst[3] = src[2] * 2;
        }
        ;
    }
    ;
    src += (2 * src_stride);
    {
        {
            int sum = 0;
            for (int k = 0; k < 4; ++k) {
                sum += src[k];
            }
            dst[4] = sum / 4;
        }
        ;
        {
            dst[5] = src[0] ^ src_stride;
            dst[6] = dst_stride ? src[1] % dst_stride : src[1];
        }
        ;
    }
    ;
    dst += (2 * dst_stride);
}
}
