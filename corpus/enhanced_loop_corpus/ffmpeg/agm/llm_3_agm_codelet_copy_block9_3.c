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
    ptrdiff_t offset;
    for (offset = 0; offset <= 8; offset += 4) {
        if (offset == 0) {
            (((union unaligned_64 *)dst)->l) = (((const union unaligned_64 *)src)->l);
        } else if (offset == 8) {
            dst[offset] = src[offset];
        }
    }
    dst += dstStride;
    src += srcStride;
}
}
