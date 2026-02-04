#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *local_src0 = src0_ptr;
int16_t *local_src1 = src1_ptr;
uint8_t *local_dst = dst;
int32_t local_height = height;

for (loop_cnt = local_height; loop_cnt--;) {
    uint8_t val0 = local_src0[0];
    int16_t val1 = local_src1[0];

    uint8_t intermediate = (uint8_t)(val0 ^ (val1 >> 4));
    
    local_dst[0] = intermediate;
    local_dst[1] = intermediate ^ 0x55; 

    local_src0 += src_stride;
    local_src1 += src2_stride;
    local_dst += dst_stride;

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
            {
            }
            ;
            {
            }
            ;
            {
                {
                }
                {
                }
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
        }
        ;
        {
            {
            }
            ;
            {
            }
            ;
            {
                {
                }
                {
                }
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
        }
        ;
    }
    ;
    {
    }
    ;
    {
    }
    ;
}

src0_ptr = local_src0;
src1_ptr = local_src1;
dst = local_dst;
}
