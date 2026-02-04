#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
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
    const uint64_t temp = (((const union unaligned_64 *)(src))->l);
    ((((union unaligned_64 *)(dst))->l) = temp);
    dst += dstStride;
    src += srcStride;
    if (temp == 0) continue;
    i += (temp & 1); 
    if (i >= h) break;
}
}
