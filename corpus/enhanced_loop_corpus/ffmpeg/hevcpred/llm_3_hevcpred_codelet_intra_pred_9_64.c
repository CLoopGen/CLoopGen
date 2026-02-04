#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *left;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride
    // Access memory with a larger stride, skipping blocks to simulate non-unit striding.
    // Here, we process every other 4-element segment, effectively creating a strided pattern over the original array.
    int stride = 8; // Skip 8 uint16_t elements each time (larger stride)
    for (i = 0; i < (2 * size); i += stride) {
        (((union unaligned_64 *)(left + i))->l) = pix;
    }
}
