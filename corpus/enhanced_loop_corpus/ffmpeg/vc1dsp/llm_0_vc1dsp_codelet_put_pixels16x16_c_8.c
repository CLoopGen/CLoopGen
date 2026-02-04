#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 4; outer++) {
    for (int inner = 0; inner < 4; inner++) {
        int idx = outer * 4 + inner;
        ((uint32_t*)block)[idx] = ((const union unaligned_32*)(pixels + idx * 4))->l;
    }
    pixels += line_size;
    block += line_size;
}
}
