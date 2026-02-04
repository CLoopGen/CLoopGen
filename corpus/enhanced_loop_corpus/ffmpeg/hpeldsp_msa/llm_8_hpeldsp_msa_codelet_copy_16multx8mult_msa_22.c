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
extern int32_t cnt;
extern int32_t loop_cnt;
extern  uint8_t *src_tmp;
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 3); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        {
            {
                uint64_t sum1 = 0, sum2 = 0;
                sum1 += src_tmp[0] + src_tmp[1];
                sum2 += src_tmp[2] + src_tmp[3];
                dst_tmp[0] = (uint8_t)(sum1 >> 1);
                dst_tmp[1] = (uint8_t)(sum2 >> 1);
            }
            ;
            {
                uint64_t sum = src_tmp[4] * 2 + src_tmp[5] * 3;
                dst_tmp[2] = (uint8_t)((sum + 2) / 5);
            }
            ;
        }
        ;
        {
            uint64_t val;
            val = (src_tmp[8] + src_tmp[9] + src_tmp[10] + src_tmp[11]) << 1;
            dst_tmp[3] = (uint8_t)(val >> 2);
        }
        ;
        src_tmp += (4 * src_stride);
        {
            {
                dst_tmp[4] = (src_tmp[0] > 127) ? 255 : 0;
            }
            ;
            {
                int avg = (src_tmp[1] + src_tmp[2]) / 2;
                dst_tmp[5] = (uint8_t)avg;
            }
            ;
        }
        ;
        dst_tmp += (4 * dst_stride);
    }
    src += 8;
    dst += 8;
}
}
