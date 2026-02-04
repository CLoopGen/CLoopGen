#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int vector_width = 4;
for (loop_cnt = (height >> 2); loop_cnt--;) {
    for (int offset = 0; offset < 4 * src_stride; offset += src_stride) {
        uint8_t temp[4];
        temp[0] = src[offset + 0 * src_stride];
        temp[1] = src[offset + 1 * src_stride];
        temp[2] = src[offset + 2 * src_stride];
        temp[3] = src[offset + 3 * src_stride];

        for (int v = 0; v < vector_width; ++v) {
            dst[v] = temp[v];
        }
        dst += dst_stride;
    }
    src += 4 * src_stride;
}
}
