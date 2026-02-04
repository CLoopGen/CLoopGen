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
uint8_t *temp_src = src;
uint8_t *temp_dst = dst;
int32_t offset = 0;

for (loop_cnt = (height >> 1); loop_cnt--;) {
    temp_src += src_stride;
    temp_src += src_stride;
    offset += dst_stride;
    temp_dst = dst + 2 * offset;

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
}
src = temp_src;
dst = temp_dst;
}
