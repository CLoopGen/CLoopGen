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
extern uint8_t *src_orig;
extern uint8_t *dst_orig;
extern int32_t v_cnt;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; height; height -= 4) {
    src_orig = src - 1;
    dst_orig = dst;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    for (v_cnt = 0; v_cnt < width; v_cnt += 16) {
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
        src_orig += 16;
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
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
        dst_orig += 16;
    }
    src += (src_stride << 2);
    dst += (dst_stride << 2);
}

}
