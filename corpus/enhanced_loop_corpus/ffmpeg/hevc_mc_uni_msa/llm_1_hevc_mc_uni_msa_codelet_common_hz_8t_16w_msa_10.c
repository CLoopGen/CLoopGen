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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    for (int level1 = 0; level1 < 1; ++level1) {
        {
        }
        ;
        {
        }
        ;
        src += (2 * src_stride);
        {
        }
        ;
        {
        }
        ;
        src += (2 * src_stride);
        for (int level2 = 0; level2 < 1; ++level2) {
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
            for (int level3 = 0; level3 < 4; ++level3) {
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
                    }
                    ;
                    {
                    }
                    ;
                }
                ;
                dst += dst_stride;
            }
            for (int level3 = 0; level3 < 1; ++level3) {
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
            for (int level3 = 0; level3 < 1; ++level3) {
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
        dst += dst_stride;
        dst += dst_stride;
    }
}
}
