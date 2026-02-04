#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *base_block = block;
    for (y = 0; y < height; y++) {
        uint8_t temp = base_block[y]; // Consecutive access: treat block as contiguous array
        base_block += stride;
    }
    block = base_block;
}
