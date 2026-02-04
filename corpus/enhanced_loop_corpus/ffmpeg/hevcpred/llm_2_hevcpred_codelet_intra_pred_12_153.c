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
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of writing to every 4th element (strided), write to four consecutive elements per iteration
    for (i = 0; i < (2 * size); i += 4) {
        ((((union unaligned_64 *)(top + i + 0))->l) = (pix));
        if (i + 1 < (2 * size)) ((((union unaligned_64 *)(top + i + 1))->l) = (pix));
        if (i + 2 < (2 * size)) ((((union unaligned_64 *)(top + i + 2))->l) = (pix));
        if (i + 3 < (2 * size)) ((((union unaligned_64 *)(top + i + 3))->l) = (pix));
    }
}
