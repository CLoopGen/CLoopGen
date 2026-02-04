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
    size_t offset = i * 8; // Simulate consecutive access by treating memory as a flat array of 64-bit values
    ((union unaligned_64 *)(dst + offset))->l = ((const union unaligned_64 *)(src + offset))->l;
}
}
