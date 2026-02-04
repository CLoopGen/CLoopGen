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
    uint8_t temp1 = src_tmp[0];
    uint8_t temp2 = src_tmp[src_stride];
    uint8_t temp3, temp4;
    temp3 = temp1 ^ temp2;
    temp4 = temp2 + 1;
    dst_tmp[0] = temp3;
    dst_tmp[dst_stride] = temp4;
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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        temp1 = src_tmp[0];
        temp2 = src_tmp[src_stride];
        dst_tmp[0] = temp1 + 3;
        dst_tmp[dst_stride] = temp2 ^ temp1;
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
        src_tmp += (4 * src_stride);
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
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
        dst_tmp += (4 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
