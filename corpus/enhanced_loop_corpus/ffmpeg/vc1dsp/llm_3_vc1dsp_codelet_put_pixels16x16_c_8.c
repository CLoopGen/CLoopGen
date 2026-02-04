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
ptrdiff_t indices[4] = {0, 4, 8, 12};
for (i = 0; i < 16; i++) {
    for (int j = 0; j < 4; j++) {
        ptrdiff_t idx = indices[j];
        (*(uint32_t *)(block + idx)) = ((((const union unaligned_32 *)(pixels + idx))->l));
    }
    pixels += line_size;
    block += line_size;
}
}
