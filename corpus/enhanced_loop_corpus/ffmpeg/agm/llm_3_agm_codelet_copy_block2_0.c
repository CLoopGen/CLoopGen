#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
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
    size_t offset = i * 2; // Access pattern changed to consecutive 2-byte elements
    uint8_t *d = dst + offset;
    uint8_t *s = src + offset;
    ((((union unaligned_16 *)(d))->l) = ((((const union unaligned_16 *)(s))->l)));
}
}
