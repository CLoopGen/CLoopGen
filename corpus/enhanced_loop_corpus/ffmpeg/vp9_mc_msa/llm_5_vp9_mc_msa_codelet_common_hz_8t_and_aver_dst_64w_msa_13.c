#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = height; loop_cnt > 0; --loop_cnt) {
        for (cnt = 0; cnt < 2; ++cnt) {
            if (cnt == 0) {
                {
                    {
                    }
                    ;
                }
                ;
                {
                    {
                    }
                    ;
                }
                ;
            } else {
                continue;
            }
            {
                {
                }
                ;
            }
            ;
            if (src_stride > 0) {
                {
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
            }
            ;
            {
                {
                }
                ;
            }
            ;
        }
        src += src_stride;
        dst += dst_stride;
    }
}
