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
    // Variant 2: Strided access with increasing stride (non-unit, power-of-2 spacing)
    // Access indices using a non-linear but deterministic stride (e.g., every 8th uint16_t, which skips 4 uint64_t slots)
    // This increases spatial sparsity while maintaining deterministic access.
    int j;
    const int stride = 8;  // Stride in units of uint16_t (i.e., skip 8 elements = 4 uint64_t slots)
    for (j = 0; j < (2 * size); j += stride)
        ((((union unaligned_64 *)(left + j))->l) = (pix));
}
