#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *left;
extern int bottom_left_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((size - bottom_left_size) >> 2); ++i) {
        uint32_t offset = (size + bottom_left_size + (i << 2));
        ((((union unaligned_32 *)(left + offset))->l) = (pix));
    }
}
