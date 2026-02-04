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
    int offset;
    for (offset = 0; offset < 8; ++offset) {
        int src_idx = offset * src_stride;
        int dst_idx = offset * dst_stride;
        for (int i = 0; i < 8; ++i) {
            dst[dst_idx + i] = src[src_idx + i];
        }
    }

    src += 8 * src_stride;
    dst += 8 * dst_stride;
}
}
