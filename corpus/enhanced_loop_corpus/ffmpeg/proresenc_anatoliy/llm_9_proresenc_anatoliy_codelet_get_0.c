#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *pixels;
extern int stride;
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    ((((union unaligned_64 *)(block))->l) = ((((const union unaligned_64 *)(pixels))->l)));
    ((((union unaligned_64 *)(block + 2))->l) = ((((const union unaligned_64 *)(pixels + 8))->l)));
    ((((union unaligned_64 *)(block + 4))->l) = ((((const union unaligned_64 *)(pixels + stride))->l)));
    ((((union unaligned_64 *)(block + 6))->l) = ((((const union unaligned_64 *)(pixels + stride + 8))->l)));
    pixels += stride * 2;
    block += 8;
}
}
