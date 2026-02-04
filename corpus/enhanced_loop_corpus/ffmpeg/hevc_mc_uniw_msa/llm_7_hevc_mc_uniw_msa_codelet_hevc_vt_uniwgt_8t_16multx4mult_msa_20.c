#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t weightmul16;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern int32_t loop_cnt;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = weightmul16; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    uint8_t prev_dst_val = dst_tmp[0];
    {
        {
            {
                uint8_t scratch[4];
                for (int j = 0; j < 4; ++j) {
                    scratch[j] = src_tmp[j * src_stride] ^ 0xFF;
                }
                src_tmp += (7 * src_stride);
                for (loop_cnt = (height >> 2); loop_cnt--;) {
                    uint8_t combined = 0;
                    for (int k = 0; k < 4; ++k) {
                        uint8_t raw = src_tmp[k * src_stride];
                        combined ^= (raw + scratch[k % 4]) ^ prev_dst_val;
                    }
                    dst_tmp[0] = combined;
                    prev_dst_val = combined;

                    src_tmp += (4 * src_stride);
                    dst_tmp += (4 * dst_stride);

                    for (int m = 1; m < 4; ++m) {
                        dst_tmp[m * dst_stride] = combined ^ (m * 17);
                    }
                }
            }
        }
    }
    src += 16;
    dst += 16;
}
}
