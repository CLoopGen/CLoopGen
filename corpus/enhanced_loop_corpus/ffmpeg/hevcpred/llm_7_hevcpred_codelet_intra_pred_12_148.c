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
    uint64_t local_pix[4];
    for (i = 0; i < (size); i += 4) {
        // Remove potential write-after-write hazards by computing values independently
        local_pix[0] = pix + 0;
        local_pix[1] = pix + 1;
        local_pix[2] = pix + 2;
        local_pix[3] = pix + 3;
        // Scatter writes to avoid WAW dependencies (assuming alignment allows)
        if (i + 0 < size) (((union unaligned_64 *)(left + size + i + 0))->l) = local_pix[0];
        if (i + 1 < size) (((union unaligned_64 *)(left + size + i + 1))->l) = local_pix[1];
        if (i + 2 < size) (((union unaligned_64 *)(left + size + i + 2))->l) = local_pix[2];
        if (i + 3 < size) (((union unaligned_64 *)(left + size + i + 3))->l) = local_pix[3];
    }
}
