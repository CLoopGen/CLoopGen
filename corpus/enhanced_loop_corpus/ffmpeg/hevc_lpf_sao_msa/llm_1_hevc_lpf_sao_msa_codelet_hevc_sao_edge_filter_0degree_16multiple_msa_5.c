#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t *src;
extern int32_t src_stride;
extern int32_t width;
extern int32_t height;
extern uint8_t *dst_ptr;
extern uint8_t *src_minus1;
extern int32_t v_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height; height--) {
    src_minus1 = src - 1;
    for (int row = 0; row < 4 && height >= 4 - row; row++) {
        for (v_cnt = 0; v_cnt < width; v_cnt += 16) {
            src_minus1 += 16;
            dst_ptr = dst + v_cnt;
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
                    {
                    }
                    {
                    }
                }
                {
                    {
                    }
                    {
                    }
                }
            }
            ;
            {
                {
                    {
                    }
                    {
                    }
                }
                {
                    {
                    }
                    {
                    }
                }
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
        src += src_stride;
        dst += dst_stride;
    }
    if (height >= 4) {
        src += (src_stride << 2) - (4 * src_stride);
        dst += (dst_stride << 2) - (4 * dst_stride);
    }
}
}
