#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_ptr;
extern int32_t src_stride;
extern uint8_t *ref_ptr;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ht_cnt = (height >> 2); ht_cnt--;) {
    src_ptr += src_stride;
    ref_ptr += ref_stride;
    uint8_t temp1 = src_ptr[0];
    uint8_t temp2 = ref_ptr[0];
    src_ptr[0] = temp2;
    ref_ptr[0] = temp1;
    {
        {
            src_ptr[1] ^= ref_ptr[-1];
        }
        ;
        {
            ref_ptr[2] += src_ptr[-2];
        }
        ;
        {
            src_ptr[3] -= ref_ptr[1];
        }
        ;
    }
    ;
    src_ptr += src_stride;
    ref_ptr += ref_stride;
    {
        {
            src_ptr[1] ^= ref_ptr[-1];
        }
        ;
        {
            ref_ptr[2] += src_ptr[-2];
        }
        ;
        {
            src_ptr[3] -= ref_ptr[1];
        }
        ;
    }
    ;
    src_ptr += src_stride;
    ref_ptr += ref_stride;
    {
        {
            src_ptr[1] ^= ref_ptr[-1];
        }
        ;
        {
            ref_ptr[2] += src_ptr[-2];
        }
        ;
        {
            src_ptr[3] -= ref_ptr[1];
        }
        ;
    }
    ;
    src_ptr += src_stride;
    ref_ptr += ref_stride;
    {
        {
            src_ptr[1] ^= ref_ptr[-1];
        }
        ;
        {
            ref_ptr[2] += src_ptr[-2];
        }
        ;
        {
            src_ptr[3] -= ref_ptr[1];
        }
        ;
    }
    ;
}
}
