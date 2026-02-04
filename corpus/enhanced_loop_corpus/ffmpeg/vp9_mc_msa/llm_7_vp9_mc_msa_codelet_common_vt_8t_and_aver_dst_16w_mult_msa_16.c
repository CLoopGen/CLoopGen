#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern  uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;

    uint8_t val_accum = 0;
    for (int i = 0; i < 4; ++i) {
        val_accum += src_tmp[i * src_stride];
    }

    dst_tmp[0] = val_accum;
    dst_tmp[dst_stride] = val_accum;
    dst_tmp[2 * dst_stride] = val_accum;
    dst_tmp[3 * dst_stride] = val_accum;

    src_tmp += 7 * src_stride;

    uint8_t prev_dst_val = dst_tmp[0];
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t new_val = src_tmp[0] + src_tmp[2 * src_stride];
        uint8_t computed = (new_val << 1) | (prev_dst_val & 1);

        dst_tmp[0] = computed;
        dst_tmp[dst_stride] = computed ^ 0xFF;
        dst_tmp[2 * dst_stride] = src_tmp[src_stride];
        dst_tmp[3 * dst_stride] = src_tmp[3 * src_stride];

        prev_dst_val = computed;

        src_tmp += 4 * src_stride;
        dst_tmp += 4 * dst_stride;

        dst_tmp[-4 * dst_stride] += dst_tmp[-3 * dst_stride];
        dst_tmp[-3 * dst_stride] += dst_tmp[-2 * dst_stride];
        dst_tmp[-2 * dst_stride] += dst_tmp[-1 * dst_stride];
        dst_tmp[-1 * dst_stride] += dst_tmp[0];
    }

    src += 16;
    dst += 16;
}
}
