#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 128; loop_cnt--;) {
        int i;
        for (i = 0; i < 4; ++i) {
            int offset = i * 8;
            dst[offset + 0] = (src0_ptr[0] > 128) ? src0_ptr[0] : (src0_ptr[0] ^ 0xFF);
            dst[offset + 1] = (src0_ptr[1] > 128) ? src0_ptr[1] : (src0_ptr[1] ^ 0xFF);
            dst[offset + 2] = (src0_ptr[2] > 128) ? src0_ptr[2] : (src0_ptr[2] ^ 0xFF);
            dst[offset + 3] = (src0_ptr[3] > 128) ? src0_ptr[3] : (src0_ptr[3] ^ 0xFF);
            dst[offset + 4] = (src0_ptr[4] > 128) ? src0_ptr[4] : (src0_ptr[4] ^ 0xFF);
            dst[offset + 5] = (src0_ptr[5] > 128) ? src0_ptr[5] : (src0_ptr[5] ^ 0xFF);
            dst[offset + 6] = (src0_ptr[6] > 128) ? src0_ptr[6] : (src0_ptr[6] ^ 0xFF);
            dst[offset + 7] = (src0_ptr[7] > 128) ? src0_ptr[7] : (src0_ptr[7] ^ 0xFF);

            src0_ptr += 8;
        }

        for (i = 0; i < 2; ++i) {
            src1_ptr[i] = (int16_t)(src1_ptr[i] * 1.5f + 32.0f);
        }

        src1_ptr += src2_stride - 2;
        dst += dst_stride;
    }
}
