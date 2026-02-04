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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        {
            {
                if ((uintptr_t)src & 1) {
                    src += src_stride;
                } else {
                    src += (src_stride << 1);
                    goto skip_second_increment;
                }
            }
            src += src_stride;
        }
        skip_second_increment:
        {
            {
                if ((uintptr_t)dst & 1) {
                    dst += dst_stride;
                } else {
                    dst += (dst_stride << 1);
                    goto skip_dst_update;
                }
            }
            dst += dst_stride;
        }
        skip_dst_update:
        continue;
    }
}
