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
    for (loop_cnt = height; loop_cnt--;) {
        for (int outer = 0; outer < 1; ++outer) {
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
            src0_ptr += src_stride;
            for (int mid1 = 0; mid1 < 1; ++mid1) {
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
                        {
                        }
                        ;
                    }
                    ;
                }
                ;
            }
            src1_ptr += src2_stride;
            for (int mid2 = 0; mid2 < 1; ++mid2) {
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
            }
            ;
            for (int mid3 = 0; mid3 < 1; ++mid3) {
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
            }
            ;
            for (int mid4 = 0; mid4 < 1; ++mid4) {
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
                        {
                        }
                        ;
                    }
                    ;
                }
                ;
            }
            dst += dst_stride;
        }
    }
}
