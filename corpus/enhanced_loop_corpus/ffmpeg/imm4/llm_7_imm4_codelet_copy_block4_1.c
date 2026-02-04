#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    union unaligned_32 *d = (union unaligned_32 *)dst;
    const union unaligned_32 *s = (const union unaligned_32 *)src;
    ptrdiff_t d_stride = dstStride / sizeof(uint32_t);
    ptrdiff_t s_stride = srcStride / sizeof(uint32_t);
    for (i = 0; i < h; i++) {
        d[0].l = s[0].l;
        d += d_stride;
        s += s_stride;
    }
}
