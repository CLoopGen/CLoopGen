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
    uint64_t temp1, temp2;
    for (i = 0; i < 8; i++) {
        temp1 = ((const union unaligned_64 *)(pixels))->l;
        temp2 = ((const union unaligned_64 *)(pixels + 8))->l;
        (((union unaligned_64 *)(block))->l) = temp1;
        (((union unaligned_64 *)(block + 4))->l) = temp2;
        pixels += stride;
        block += 8;
    }
}
