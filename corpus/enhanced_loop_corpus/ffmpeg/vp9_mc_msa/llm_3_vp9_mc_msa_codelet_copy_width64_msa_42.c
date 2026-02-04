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
int32_t i;
for (i = 0; i < height; i += 4) {
    int32_t idx_src[4], idx_dst[4];
    for (int j = 0; j < 4; ++j) {
        idx_src[j] = (i + j) * src_stride;
        idx_dst[j] = (i + j) * dst_stride;
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
    src += src_stride;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    src += src_stride;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    src += src_stride;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    src += src_stride;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    dst += dst_stride;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    dst += dst_stride;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    dst += dst_stride;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    dst += dst_stride;
}
}
