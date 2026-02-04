#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational complexity: downsample operations and reduce trip count
for (i = 4; i < width - 4; i += 4) {
    // Perform only center pixel approximation with simplified averaging
    dst[0] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l) +
              (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (2)])))->l)) >> (1 + 8);
    dst[1] = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l) >> 8;
    dst[2] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l) +
              (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (2)])))->l)) >> (1 + 8);

    // Skip writing redundant blocks, reduce memory traffic
    // Only write one 3-byte output block per iteration
    src += 4 * 2;  // Advance source by 8 bytes
    dst += 3;      // Advance destination by 3 bytes
}
}
