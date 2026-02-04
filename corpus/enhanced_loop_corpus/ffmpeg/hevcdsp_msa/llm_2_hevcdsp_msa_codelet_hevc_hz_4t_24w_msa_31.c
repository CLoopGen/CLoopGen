#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        dst_tmp[0 * dst_stride] = (int16_t)(src[0 * src_stride]);
        dst_tmp[1 * dst_stride] = (int16_t)(src[1 * src_stride]);
        dst_tmp[2 * dst_stride] = (int16_t)(src[2 * src_stride]);
        dst_tmp[3 * src_stride] = (int16_t)(src[3 * src_stride]);

        src += (4 * src_stride);
        dst_tmp += (4 * dst_stride);

        dst[0] = dst_tmp[-4 * dst_stride];
        dst[1] = dst_tmp[-3 * dst_stride];
        dst[2] = dst_tmp[-2 * dst_stride];
        dst[3] = dst_tmp[-1 * dst_stride];

        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
    }
}
