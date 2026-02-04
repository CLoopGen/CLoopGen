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
    int offset;
    // Access memory with non-unit stride (every 2nd byte)
    for (offset = 0; offset < 9; offset += 2) {
        dst[offset] = src[offset];
    }
    // Handle last byte if not covered
    if (offset < 9) {
        dst[8] = src[8];
    }
    dst += dstStride;
    src += srcStride;
}
}
