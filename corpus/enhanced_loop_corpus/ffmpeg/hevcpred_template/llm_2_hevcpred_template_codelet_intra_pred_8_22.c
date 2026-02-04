#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled writes (writing two uint32_t values consecutively)
    for (i = 0; i < (size - 3); i += 8) {
        (((union unaligned_32 *)(top + i))->l) = (pix);
        if (i + 4 < size) (((union unaligned_32 *)(top + i + 4))->l) = (pix);
    }
}
