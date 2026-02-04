#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t temp[4];
    temp[0] = src[0]; temp[1] = src[1]; temp[2] = src[2]; temp[3] = src[3];
    dst[0] = temp[0]; dst[1] = temp[1]; dst[2] = temp[2]; dst[3] = temp[3];
    dst += dstStride;
    src += srcStride;
}
}
