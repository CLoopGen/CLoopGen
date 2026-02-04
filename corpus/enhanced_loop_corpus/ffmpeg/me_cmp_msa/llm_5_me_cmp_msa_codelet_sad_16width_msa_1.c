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
    for (ht_cnt = (height >> 2); ht_cnt--;) {
        {
        }
        ;
        if ((intptr_t)src % 4 == 0) {
            src += (2 * src_stride);
        } else {
            src += src_stride;
        }
        {
        }
        ;
        if ((intptr_t)ref % 4 == 0) {
            ref += (2 * ref_stride);
        } else {
            ref += ref_stride;
        }
        {
        }
        ;
        src += (2 * src_stride);
        {
        }
        ;
        ref += (2 * ref_stride);
    }
}
