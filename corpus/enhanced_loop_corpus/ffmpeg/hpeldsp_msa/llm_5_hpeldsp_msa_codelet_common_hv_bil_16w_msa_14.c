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
    for (loop_cnt = (height >> 3); loop_cnt-- > 0;) {
        const int skip_first_half = (height & 0x7) < 4;
        const int skip_second_half = (height & 0x7) == 0;

        {
            if (!skip_first_half) {
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
        ;
        {
            if (!skip_second_half) {
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
        ;
        src += (8 * src_stride);
        for (int i = 0; i < 5; i++) {
            if (i == 2) continue;
            {
            }
            ;
        }
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
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
        }
        ;
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
            uint8_t *pdst_m = (uint8_t *)(dst);
            if (pdst_m + dst_stride > pdst_m) {
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
        ;
        dst += (4 * dst_stride);
        {
            uint8_t *pdst_m = (uint8_t *)(dst);
            if (loop_cnt % 2 == 0) {
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
        ;
        dst += (4 * dst_stride);
    }
}
