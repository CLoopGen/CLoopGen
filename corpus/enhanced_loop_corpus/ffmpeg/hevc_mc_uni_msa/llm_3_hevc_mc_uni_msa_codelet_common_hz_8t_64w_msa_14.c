#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    int32_t idx = 0;
    for (int step = 0; step < src_stride; step += 4) {
        int32_t access_idx = (step * 3) % src_stride; // Strided, non-linear access
        dst[idx++] = src[access_idx];
        if (idx >= dst_stride) break;
    }
    src += src_stride;
    dst += dst_stride;
}
}
