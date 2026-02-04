#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 3); cnt--;) {
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    src += src_stride << 1;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    src += src_stride << 1;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    dst += dst_stride << 1;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    dst += dst_stride << 1;
}
}
