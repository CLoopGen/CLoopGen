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
for (ht_cnt = (height >> 3); ht_cnt--;) {
    int phase1 = 1, phase2 = 1;

    if (phase1) {
        src += (4 * src_stride);
        ref += (5 * ref_stride);
        phase1 = 0;
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

    if (phase2) {
        src += (4 * src_stride);
        ref += (3 * ref_stride);
        phase2 = 0;
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
