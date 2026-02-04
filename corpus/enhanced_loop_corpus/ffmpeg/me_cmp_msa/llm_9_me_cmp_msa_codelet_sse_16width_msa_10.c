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
for (ht_cnt = (height >> 1); ht_cnt--;) {
    src_ptr += src_stride << 1;
    ref_ptr += ref_stride << 1;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    src_ptr += src_stride << 1;
    ref_ptr += ref_stride << 1;
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
