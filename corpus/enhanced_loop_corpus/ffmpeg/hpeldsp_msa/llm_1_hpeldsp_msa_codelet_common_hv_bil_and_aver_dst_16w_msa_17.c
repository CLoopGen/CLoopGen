#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        {
            {
                for (int inner = 0; inner < 1; ++inner) {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
                ;
                for (int inner = 0; inner < 1; ++inner) {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
            }
            ;
            {
                for (int inner = 0; inner < 1; ++inner) {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
                ;
                for (int inner = 0; inner < 1; ++inner) {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
            }
            ;
        }
        ;
        {
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
            }
            ;
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
            }
            ;
        }
        ;
        src += (8 * src_stride);
        for (int step = 0; step < 8; ++step) {
            {
            }
            ;
            dst += dst_stride;
        }
    }
}
