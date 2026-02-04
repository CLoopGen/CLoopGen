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
ptrdiff_t offset;
for (i = 0; i < h; i++) {
    offset = i * (dstStride / 8); 
    ((uint64_t*)(dst + (offset * 8)))[0] = ((const uint64_t*)(src + (offset * 8)))[0];
    ((uint64_t*)(dst + (offset * 8)))[1] = ((const uint64_t*)(src + (offset * 8)))[1];
}
}
