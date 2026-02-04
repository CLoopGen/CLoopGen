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
    for (loop_cnt = (height >> 3); loop_cnt--; ) {
        uint8_t local_height = height;
        int skip_src_update = 0;

        if (local_height >= 8) {
            {
                {
                }
                ;
                {
                    if ((loop_cnt & 1) == 0) {
                        skip_src_update = 1;
                    } else {
                        {
                        }
                        ;
                    }
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

        if (!skip_src_update) {
            src += (8 * src_stride);
        }

        {
            {
            }
            {
            }
        }
        ;
        {
            {
            }
            {
            }
        }
        ;

        if (loop_cnt % 3 == 0) {
            {
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
        } else {
            {
                {
                }
                {
                }
            }
            ;
            {
                {
                }
                {
                }
            }
            ;
        }

        dst += (8 * dst_stride);
    }
}
