#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        {
            {
                if (src_stride <= 2) {
                    {
                    }
                    ;
                } else {
                    {
                        if (height < 16) goto skip_first_part;
                    }
                    ;
                }
            }
            ;
            skip_first_part:
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
        ;
        {
            if (loop_cnt > 1) {
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
        ;
        src += (8 * src_stride);
        {
            if (dst_stride % 4 == 0) {
                {
                    {
                    }
                    {
                    }
                }
            } else {
                {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
                ;
                dst += dst_stride;
                goto after_dst_update;
            }
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
        after_dst_update:
        dst += (4 * dst_stride);
        if (dst_stride >= 8) {
            dst += (4 * dst_stride);
        }
    }
}
