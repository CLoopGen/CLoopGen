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
    int offset = i * 8; // Simulate consecutive access by processing 8-byte chunks
    uint8_t *d = dst + offset;
    uint8_t *s = src + offset;
    if ((d + 7 < dst + h * dstStride) && (s + 7 < src + h * srcStride)) {
        ((((union unaligned_64 *)(d))->l) = ((((const union unaligned_64 *)(s))->l)));
    }
}
}
