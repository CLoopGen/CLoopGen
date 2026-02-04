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
    for (int depth1 = 0; depth1 < 1; ++depth1) {
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
    ref += (5 * ref_stride);
    for (int i = 0; i < 9; ++i) {
        {
        }
        ;
    }
    src += (4 * src_stride);
    for (int depth2 = 0; depth2 < 1; ++depth2) {
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
    ref += (3 * ref_stride);
    for (int j = 0; j < 8; ++j) {
        {
        }
        ;
    }
}
}
