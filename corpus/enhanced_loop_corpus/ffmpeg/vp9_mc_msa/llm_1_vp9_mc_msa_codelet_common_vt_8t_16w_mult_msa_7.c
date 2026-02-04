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
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    {
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
        }
        ;
        {
        }
        ;
    }
    ;
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
        }
        ;
    }
    ;
    src_tmp += (7 * src_stride);
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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        for (int inner = 0; inner < 2; inner++) {
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
            src_tmp += (2 * src_stride);
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
            dst_tmp += (2 * dst_stride);
        }
    }
    src += 16;
    dst += 16;
}
}
