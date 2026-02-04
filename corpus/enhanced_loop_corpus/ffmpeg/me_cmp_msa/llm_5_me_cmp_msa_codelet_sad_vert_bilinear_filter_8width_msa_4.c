#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *ref;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ht_cnt = (height >> 3); ht_cnt-- > 0;) {
    if (ht_cnt < (height >> 4)) {
        src += (8 * src_stride);
        ref += (8 * ref_stride);
        continue;
    }
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    src += (4 * src_stride);
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
    }
    ;
    ref += (4 * ref_stride);
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
    src += (4 * src_stride);
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
    }
    ;
    ref += (4 * ref_stride);
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
}
