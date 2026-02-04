#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height / 8); cnt--;) {
        {
            {
                for (int j = 0; j < 1; ++j) {
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
            }
            ;
            {
                for (int k = 0; k < 1; ++k) {
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
            }
            ;
        }
        ;
        src += (8 * src_stride);
        {
            {
                for (int m = 0; m < 1; ++m) {
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
            }
            ;
            {
                for (int n = 0; n < 1; ++n) {
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
            {
            }
            {
            }
        }
        ;
        {
            {
                for (int p = 0; p < 1; ++p) {
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
            }
            ;
            {
                for (int q = 0; q < 1; ++q) {
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
            }
            ;
        }
        ;
        dst += (8 * dst_stride);
    }
}
