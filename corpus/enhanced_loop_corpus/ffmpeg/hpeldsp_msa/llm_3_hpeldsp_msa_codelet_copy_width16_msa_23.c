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
for (cnt = (height / 12); cnt--;) {
    int32_t offset_src, offset_dst;
    int32_t base_idx;

    for (base_idx = 0; base_idx < 12; base_idx++) {
        offset_src = (base_idx < 8 ? base_idx : base_idx - 8 + 4) * src_stride;
        offset_dst = (base_idx < 8 ? base_idx : base_idx - 8 + 4) * dst_stride;

        dst[offset_dst] = src[offset_src];
        dst[offset_dst + 1] = src[offset_src + 1];
        dst[offset_dst + 2] = src[offset_src + 2];
        dst[offset_dst + 3] = src[offset_src + 3];
        if (base_idx < 8) {
            dst[offset_dst + 4] = src[offset_src + 4];
            dst[offset_dst + 5] = src[offset_src + 5];
            dst[offset_dst + 6] = src[offset_src + 6];
            dst[offset_dst + 7] = src[offset_src + 7];
        }
    }

    src += 12 * src_stride;
    dst += 12 * dst_stride;
}
}
