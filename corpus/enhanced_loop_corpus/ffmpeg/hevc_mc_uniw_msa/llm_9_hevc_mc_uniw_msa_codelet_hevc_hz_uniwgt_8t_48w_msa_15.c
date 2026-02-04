#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 32; loop_cnt--;) {
        uint32_t acc = 0;
        acc += src[0] + src[1];
        acc += src[2] + src[3];
        acc += src[4] + src[5];
        acc += src[6] + src[7];
        acc = (acc * 11) % 257;
        dst[0] = acc & 0xFF;
        for (int inner = 0; inner < 2; inner++) {
            acc += src[8 + inner * 4] ^ dst[inner];
            dst[1 + inner] = acc >> (inner * 7);
        }
        src += src_stride * 2;
        dst += dst_stride * 2;
        loop_cnt--; // Effectively reduces trip count further
    }
}
