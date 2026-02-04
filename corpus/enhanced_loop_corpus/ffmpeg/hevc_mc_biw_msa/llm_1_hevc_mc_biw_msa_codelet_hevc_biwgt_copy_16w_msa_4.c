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
    for (loop_cnt = (height >> 4); loop_cnt--;) {
        for (int outer = 0; outer < 2; ++outer) {
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            src0_ptr += (2 * src_stride);
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
            src1_ptr += (2 * src2_stride);
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
            }
            ;
            {
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
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            dst += (2 * dst_stride);
        }
    }
}
