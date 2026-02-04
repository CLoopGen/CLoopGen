#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        for (int32_t i = 0; i < 2; ++i) {
            src += src_stride;
            for (int32_t j = 0; j < 2; ++j) {
                dst += dst_stride;
                for (int32_t k = 0; k < 4; ++k) {
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
                                ;
                                {
                                }
                                ;
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
                }
            }
        }
    }
}
