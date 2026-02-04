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
    size_t offset = i * 16; // Interleaved access with stride of 16 bytes across iterations
    ((uint64_t*)(dst + offset))[0] = ((const uint64_t*)(src + offset))[0];
    ((uint64_t*)(dst + offset))[1] = ((const uint64_t*)(src + offset))[1];
}
// Note: This variant assumes dst and src are base pointers and not updated per iteration.
// It changes access from sequential pointer update to strided, iteration-dependent offset.
}
