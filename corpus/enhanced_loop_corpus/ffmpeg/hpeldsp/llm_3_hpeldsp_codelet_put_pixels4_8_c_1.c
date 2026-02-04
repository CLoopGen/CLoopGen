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
    int outer = 0;
    int inner;
    for (outer = 0; outer < h; outer++) {
        for (inner = 0; inner < 1; inner++) {  // Nested: depth increased to 2
            *((uint32_t *)block) = (((const union unaligned_32 *)(pixels))->l);
            pixels += line_size;
            block += line_size;
        }
    }
}
