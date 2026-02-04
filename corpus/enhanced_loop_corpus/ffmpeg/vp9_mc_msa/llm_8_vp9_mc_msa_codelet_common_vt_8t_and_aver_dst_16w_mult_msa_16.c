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
for (cnt = (width >> 3); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    {
        {
            {
                {
                    src_tmp += src_stride;
                    dst_tmp += dst_stride;
                }
                ;
                {
                    src_tmp += 2 * src_stride;
                    dst_tmp += 2 * dst_stride;
                }
                ;
            }
            ;
        }
        ;
        {
            src_tmp += 3 * src_stride;
            dst_tmp += 3 * dst_stride;
        }
        ;
    }
    ;
    {
        {
            {
                src_tmp += 4 * src_stride;
                dst_tmp += 4 * dst_stride;
            }
            ;
            {
                src_tmp += 5 * src_stride;
                dst_tmp += 5 * dst_stride;
            }
            ;
        }
        ;
        {
            {
                src_tmp += 6 * src_stride;
                dst_tmp += 6 * dst_stride;
            }
            ;
        }
        ;
    }
    ;
    src_tmp += (7 * src_stride);
    {
        {
            src_tmp += 8 * src_stride;
            dst_tmp += 8 * dst_stride;
        }
        ;
        {
            src_tmp += 9 * src_stride;
            dst_tmp += 9 * dst_stride;
        }
        ;
    }
    ;
    {
        src_tmp += 10 * src_stride;
        dst_tmp += 10 * dst_stride;
    }
    ;
    {
        {
            src_tmp += 11 * src_stride;
            dst_tmp += 11 * dst_stride;
        }
        ;
        {
            src_tmp += 12 * src_stride;
            dst_tmp += 12 * dst_stride;
        }
        ;
    }
    ;
    {
        src_tmp += 13 * src_stride;
        dst_tmp += 13 * dst_stride;
    }
    ;
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        {
            src_tmp += src_stride;
            dst_tmp += dst_stride;
        }
        ;
        src_tmp += (4 * src_stride);
        {
            dst_tmp += dst_stride;
        }
        ;
        {
            src_tmp += 2 * src_stride;
            dst_tmp += 2 * dst_stride;
        }
        ;
        {
            src_tmp += 3 * src_stride;
            dst_tmp += 3 * dst_stride;
        }
        ;
        {
            src_tmp += 4 * src_stride;
            dst_tmp += 4 * dst_stride;
        }
        ;
        {
            src_tmp += 5 * src_stride;
            dst_tmp += 5 * dst_stride;
        }
        ;
        {
            src_tmp += 6 * src_stride;
            dst_tmp += 6 * dst_stride;
        }
        ;
        {
            src_tmp += 7 * src_stride;
            dst_tmp += 7 * dst_stride;
        }
        ;
        {
            src_tmp += 8 * src_stride;
            dst_tmp += 8 * dst_stride;
        }
        ;
        {
            src_tmp += 9 * src_stride;
            dst_tmp += 9 * dst_stride;
        }
        ;
        {
            src_tmp += 10 * src_stride;
            dst_tmp += 10 * dst_stride;
        }
        ;
        {
            src_tmp += 11 * src_stride;
            dst_tmp += 11 * dst_stride;
        }
        ;
        dst_tmp += (4 * dst_stride);
    }
    src += 32;
    dst += 32;
}
}
