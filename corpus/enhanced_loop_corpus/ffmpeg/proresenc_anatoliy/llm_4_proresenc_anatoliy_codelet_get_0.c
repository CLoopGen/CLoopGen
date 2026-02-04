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
for (i = 0; i < 8; i++) {
    if (i % 2 == 0) {
        ((((union unaligned_64 *)(block))->l) = ((((const union unaligned_64 *)(pixels))->l)));
    } else {
        ((((union unaligned_64 *)(block + 4))->l) = ((((const union unaligned_64 *)(pixels + 8))->l)));
    }
    pixels += stride;
    block += 8;
}
}
