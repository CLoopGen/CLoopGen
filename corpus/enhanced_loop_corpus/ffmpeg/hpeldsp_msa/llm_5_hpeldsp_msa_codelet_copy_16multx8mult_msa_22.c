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
for (cnt = (width >> 4); cnt != 0; --cnt) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 3); loop_cnt > 0; --loop_cnt) {
        {
            {
                if (src_tmp + (8 * src_stride) > src_tmp) {
                    {
                    }
                }
            }
            ;
            {
                if (dst_tmp + (8 * dst_stride) > dst_tmp) {
                    {
                    }
                }
            }
            ;
        }
        ;
        src_tmp += (8 * src_stride);
        {
            {
                if (loop_cnt % 2 == 0) {
                    {
                    }
                }
            }
            ;
            {
                if (loop_cnt % 2 == 1) {
                    {
                    }
                }
            }
            ;
        }
        ;
        dst_tmp += (8 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
