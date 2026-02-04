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
extern int32_t width;
extern uint8_t *src0_ptr_tmp;
extern int16_t *src1_ptr_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (cnt = (width >> 4); cnt--;) {
    src0_ptr_tmp = src0_ptr;
    src1_ptr_tmp = src1_ptr;
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
    src0_ptr_tmp += (7 * src_stride);
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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        {
        }
        ;
        src0_ptr_tmp += (2 * src_stride);
        {
        }
        ;
        {
        }
        ;
        src1_ptr_tmp += (2 * src2_stride);
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
        dst_tmp += (2 * dst_stride);
    }
    src0_ptr += 16;
    src1_ptr += 16;
    dst += 16;
}

}
