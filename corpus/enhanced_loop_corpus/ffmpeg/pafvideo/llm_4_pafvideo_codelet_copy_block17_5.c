#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        if (!(i & 1)) {
            ((((union unaligned_64 *)(dst))->l) = ((((const union unaligned_64 *)(src))->l)));
            ((((union unaligned_64 *)((char *)(dst) + 8))->l) = ((((const union unaligned_64 *)((const char *)(src) + 8))->l)));
        } else {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
            dst[4] = src[4];
            dst[5] = src[5];
            dst[6] = src[6];
            dst[7] = src[7];
            dst[8] = src[8];
            dst[9] = src[9];
            dst[10] = src[10];
            dst[11] = src[11];
            dst[12] = src[12];
            dst[13] = src[13];
            dst[14] = src[14];
            dst[15] = src[15];
        }
        dst[16] = src[16];
        dst += dstStride;
        src += srcStride;
    }
}
