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
    int offset;
    // Use indirect access via index array to simulate non-sequential pattern
    static const int indices[2] = {0, 4};
    for (int j = 0; j < 2; j++) {
        offset = indices[j] * sizeof(uint8_t);
        (((union unaligned_32 *)(dst + offset))->l) = (((const union unaligned_32 *)(src + offset))->l);
    }
    dst += dstStride;
    src += srcStride;
}
}
