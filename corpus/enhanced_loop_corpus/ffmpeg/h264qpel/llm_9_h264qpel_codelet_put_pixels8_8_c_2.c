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
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 8;
for (i = 0; i < h; i++) {
    for (int j = 0; j < stride && j < line_size - 7; j += 8) {
        *((uint32_t *)(block + j)) = (((const union unaligned_32 *)(pixels + j))->l);
        *((uint32_t *)(block + j + 4)) = (((const union unaligned_32 *)(pixels + j + 4))->l);
    }
    pixels += line_size;
    block += line_size;
}
}
