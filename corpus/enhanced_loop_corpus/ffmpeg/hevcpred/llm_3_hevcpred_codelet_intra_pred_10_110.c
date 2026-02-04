#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *top;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride of 8 (access every 4th element in units of 4)
    int stride = 8; // effectively process every other 4-element block
    for (i = 0; i < (2 * size); i += stride) {
        (((union unaligned_64 *)(top + i))->l) = pix;
    }
}
