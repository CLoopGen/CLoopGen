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
    int index = i * 8;
    ((union unaligned_64 *)(block + index))->l = ((const union unaligned_64 *)(pixels + i * stride))->l;
    ((union unaligned_64 *)(block + index + 4))->l = ((const union unaligned_64 *)(pixels + i * stride + 8))->l;
}
}
