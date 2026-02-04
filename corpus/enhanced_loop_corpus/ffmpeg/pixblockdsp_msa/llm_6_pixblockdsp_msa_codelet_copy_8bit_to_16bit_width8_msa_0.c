#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t *dst_ptr;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t i;
    uint8_t *temp_src[4];
    uint8_t *temp_dst[4];

    for (cnt = (height >> 2); cnt--;) {
        temp_src[0] = src;
        temp_src[1] = src + src_stride;
        temp_src[2] = src + 2 * src_stride;
        temp_src[3] = src + 3 * src_stride;

        temp_dst[0] = dst_ptr;
        temp_dst[1] = dst_ptr + dst_stride;
        temp_dst[2] = dst_ptr + 2 * dst_stride;
        temp_dst[3] = dst_ptr + 3 * dst_stride;

        // Introduce artificial RAW dependencies: each dst write depends on prior src load
        for (i = 0; i < 4; i++) {
            temp_dst[i][0] = temp_src[i][0];  // Load from src, store to dst
        }

        src += (4 * src_stride);
        dst_ptr += (4 * 2 * dst_stride);
    }
}
