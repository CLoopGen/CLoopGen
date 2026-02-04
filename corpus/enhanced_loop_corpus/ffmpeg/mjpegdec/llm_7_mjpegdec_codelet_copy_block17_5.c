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
    uint64_t prev_load = 0;
    for (i = 0; i < h; i++) {
        union unaligned_64 *d = (union unaligned_64 *)dst;
        const union unaligned_64 *s = (const union unaligned_64 *)src;

        d->l = s->l ^ prev_load;
        ((union unaligned_64 *)((char *)dst + 8))->l = ((const union unaligned_64 *)((const char *)src + 8))->l;
        prev_load = s->l;

        dst[16] = src[16];
        dst += dstStride;
        src += srcStride;
    }
}
