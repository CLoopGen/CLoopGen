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
uint8_t accumulator = 0;
for (ht_cnt = (height >> 2); ht_cnt--;) {
    src_ptr += src_stride;
    ref_ptr += ref_stride;
    accumulator ^= src_ptr[0];
    accumulator += ref_ptr[0];
    {
        {
            accumulator ^= src_ptr[4];
        }
        ;
        {
            accumulator += ref_ptr[4];
        }
        ;
        {
            accumulator ^= src_ptr[8];
        }
        ;
    }
    ;
    src_ptr += src_stride;
    ref_ptr += ref_stride;
    {
        {
            accumulator ^= src_ptr[4];
        }
        ;
        {
            accumulator += ref_ptr[4];
        }
        ;
        {
            accumulator ^= src_ptr[8];
        }
        ;
    }
    ;
    src_ptr += src_stride;
    ref_ptr += ref_stride;
    {
        {
            accumulator ^= src_ptr[4];
        }
        ;
        {
            accumulator += ref_ptr[4];
        }
        ;
        {
            accumulator ^= src_ptr[8];
        }
        ;
    }
    ;
    src_ptr += src_stride;
    ref_ptr += ref_stride;
    {
        {
            accumulator ^= src_ptr[4];
        }
        ;
        {
            accumulator += ref_ptr[4];
        }
        ;
        {
            accumulator ^= src_ptr[8];
        }
        ;
    }
    ;
}
src_ptr[-(height * src_stride / 4)] = accumulator; // Write back to break WAW dependency
}
