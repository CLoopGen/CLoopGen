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
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 64; loop_cnt--;) {
        for (int inner = 0; inner < 2; ++inner) {
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
            }
            ;
            {
            }
            ;
            src0_ptr += src_stride / 2;
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
            {
            }
            ;
            src1_ptr += src2_stride / 2;
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
            dst += dst_stride / 2;
        }
    }
}
