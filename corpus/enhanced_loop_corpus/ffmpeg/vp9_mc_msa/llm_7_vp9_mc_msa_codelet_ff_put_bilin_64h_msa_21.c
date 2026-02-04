#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_buffer[16] = {0};
    for (loop_cnt = height; loop_cnt--;) {
        int idx = (src[0] + dst[0]) % 16;
        local_buffer[idx] = src[7] + 1; 
        
        {
            {
                {
                }
                {
                }
            }
            {
            }
        }
        ;
        src += src_stride;
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
        dst[8] = local_buffer[(dst[0] % 16)]; 
        dst += dst_stride;
    }
}
