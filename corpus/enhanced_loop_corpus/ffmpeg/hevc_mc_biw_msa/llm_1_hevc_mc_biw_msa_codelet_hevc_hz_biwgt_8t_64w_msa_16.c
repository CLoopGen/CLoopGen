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
extern uint8_t *src0_ptr_tmp;
extern uint8_t *dst_tmp;
extern int16_t *src1_ptr_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    for (uint32_t outer = 2; outer--;) {
        src0_ptr_tmp = src0_ptr + outer * 32;
        dst_tmp = dst + outer * 32;
        src1_ptr_tmp = src1_ptr + outer * 32;
        for (cnt = 2; cnt--;) {
            {
            }
            ;
            src0_ptr_tmp += 16;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            src1_ptr_tmp += 16;
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
            dst_tmp += 16;
        }
    }
    src0_ptr += src_stride;
    src1_ptr += src2_stride;
    dst += dst_stride;
}
}
