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
                for (int j = 0; j < 1; ++j) {
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
                for (int j = 0; j < 1; ++j) {
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
        src += (8 * src_stride);
        {
            {
                for (int j = 0; j < 1; ++j) {
                    {
                    }
                    {
                    }
                }
            }
            ;
            {
                for (int j = 0; j < 1; ++j) {
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
        dst += (4 * dst_stride);
        {
            {
                for (int j = 0; j < 1; ++j) {
                    {
                    }
                    {
                    }
                }
            }
            ;
            {
                for (int j = 0; j < 1; ++j) {
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
        dst += (4 * dst_stride);
    }
}
