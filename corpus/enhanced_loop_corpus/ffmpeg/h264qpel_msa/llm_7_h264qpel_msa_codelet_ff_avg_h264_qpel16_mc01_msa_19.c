#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t local_buffer[16];
ptrdiff_t idx = 0;

for (loop_cnt = 4; loop_cnt--;) {
    local_buffer[idx + 0]  = src[0];
    local_buffer[idx + 1]  = src[stride];
    local_buffer[idx + 2]  = src[2*stride];
    local_buffer[idx + 3]  = src[3*stride];

    idx += 4;

    src += (4 * stride);

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

for (loop_cnt = 4; loop_cnt--;) {
    int i = --idx;
    dst[i * stride] = local_buffer[i] ^ 0xAA;

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
    dst += (4 * stride);
}
}
