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
    int stride_factor = 4;
    ptrdiff_t extended_stride = dstStride * stride_factor;
    for (i = 0; i < h; i++) {
        uint8_t *d = dst;
        const uint8_t *s = src;
        for (int j = 0; j < stride_factor && (i + j) < h; j++) {
            ((union unaligned_64 *)d)->l = ((const union unaligned_64 *)s)->l;
            ((union unaligned_64 *)(d + 8))->l = ((const union unaligned_64 *)(s + 8))->l;
            d[16] = s[16];
            d += dstStride;
            s += srcStride;
        }
        dst += extended_stride;
        src += extended_stride;
        i += stride_factor - 1;
    }
}
