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
uint8_t *src_local = src;
uint8_t *dst_local = dst;
int32_t src_stride_local = src_stride;
int32_t dst_stride_local = dst_stride;
for (loop_cnt = (height >> 1); loop_cnt--;) {
    dst_local[0] = src_local[0];
    dst_local[1] = src_local[1];
    dst_local[dst_stride_local] = src_local[src_stride_local];
    dst_local[dst_stride_local + 1] = src_local[src_stride_local + 1];
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
    src_local += (2 * src_stride_local);
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
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    dst_local += 2 * dst_stride_local;
}
src = src_local;
dst = dst_local;
}
