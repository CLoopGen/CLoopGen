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
    for (loop_cnt = height; loop_cnt-- > 0;) {
        uint8_t *local_src = src;
        int16_t *local_dst = dst;

        src += src_stride;
        dst += dst_stride;

        if (local_src == NULL || local_dst == NULL) {
            break;
        }

        {
            {
            }
            ;
            {
            }
            ;
        }
        ;

        if (((uintptr_t)local_src & 7) == 0) {
            {
                {
                    {
                    }
                    ;
                }
                ;
                {
                }
                ;
            }
            ;
        }

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
            {
            }
            ;
            {
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
            {
            }
            ;
            {
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
            {
            }
            ;
            {
            }
            ;
        }
        ;
    }
}
