#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern uint16_t *left;
extern int size_max_y;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access writing two adjacent 64-bit values per iteration
    for (i = 0; i < (size_max_y); i += 2) {
        ((((union unaligned_64 *)(left + i))->l) = (pix));
        if (i + 1 < size_max_y)
            ((((union unaligned_64 *)(left + i + 1))->l) = (pix));
    }
}
