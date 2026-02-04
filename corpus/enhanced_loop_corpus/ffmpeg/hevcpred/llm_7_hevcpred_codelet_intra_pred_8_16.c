#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *left;
extern int size_max_y;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_pix[4];
    for (i = 0; i < (size_max_y); i += 4) {
        // Break aliasing assumption with multiple independent stores
        local_pix[0] = pix + 0;
        local_pix[1] = pix + 1;
        local_pix[2] = pix + 2;
        local_pix[3] = pix + 3;
        // Introduce intra-loop parallelism with non-overlapping writes
        ((((union unaligned_32 *)(left + i + 0))->l) = local_pix[0]);
        if (i + 4 < size_max_y)
            ((((union unaligned_32 *)(left + i + 4))->l) = local_pix[1]);
        if (i + 8 < size_max_y)
            ((((union unaligned_32 *)(left + i + 8))->l) = local_pix[2]);
        if (i + 12 < size_max_y)
            ((((union unaligned_32 *)(left + i + 12))->l) = local_pix[3]);
    }
}
