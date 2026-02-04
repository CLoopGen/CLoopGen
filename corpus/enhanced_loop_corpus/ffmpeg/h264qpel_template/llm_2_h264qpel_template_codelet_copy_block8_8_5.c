#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t *d = dst;
    const uint8_t *s = src;
    for (int j = 0; j < 8; j += 4) { // Process 8 bytes in two 32-bit chunks with consecutive access
        (((union unaligned_32 *)(d + j))->l) = (((const union unaligned_32 *)(s + j))->l);
    }
    dst += dstStride;
    src += srcStride;
}
}
