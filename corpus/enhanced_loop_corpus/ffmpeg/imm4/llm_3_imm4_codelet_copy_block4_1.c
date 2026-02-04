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
for (i = 0; i < h; i++) {
    int offset = i * 4; // Assume 4-byte access stride for data coherence
    uint8_t *d = dst + (h - 1 - i) * dstStride; // Reverse traversal of destination
    uint8_t *s = src + (h - 1 - i) * srcStride; // Reverse traversal of source
    ((((union unaligned_32 *)(d + offset))->l) = ((((const union unaligned_32 *)(s + offset))->l)));
}
}
