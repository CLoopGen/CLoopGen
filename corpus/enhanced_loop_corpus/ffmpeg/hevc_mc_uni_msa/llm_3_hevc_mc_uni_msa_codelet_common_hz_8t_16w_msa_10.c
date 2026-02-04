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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    int32_t src_offset[4] = {0, src_stride, 2*src_stride, 3*src_stride};
    int32_t dst_offset[4] = {0, dst_stride, 2*dst_stride, 3*dst_stride};

    for (int i = 0; i < 4; ++i) {
        uint8_t *s = src + src_offset[i];
        uint8_t *d = dst + dst_offset[i];

        {
        }
        ;
        {
        }
        ;

        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
