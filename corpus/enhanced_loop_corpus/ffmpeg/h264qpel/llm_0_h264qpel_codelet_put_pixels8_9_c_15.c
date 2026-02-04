#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < h; i++) {
    for (j = 0; j < 1; j++) { // Introduce inner loop with fixed iteration to increase nesting depth
        *((uint64_t *)block) = (((const union unaligned_64 *)(pixels))->l);
        *((uint64_t *)(block + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(pixels + 4 * sizeof(uint16_t)))->l);
        pixels += line_size;
        block += line_size;
    }
}
}
