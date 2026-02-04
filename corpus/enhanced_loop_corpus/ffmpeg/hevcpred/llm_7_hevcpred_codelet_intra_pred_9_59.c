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
    uint64_t local_pix[4];
    for (i = 0; i < (size_max_y); i += 4) {
        local_pix[0] = pix;
        local_pix[1] = pix + 1;
        local_pix[2] = pix + 2;
        local_pix[3] = pix + 3;
        ((union unaligned_64 *)(left + i + 0))->l = local_pix[0];
        ((union unaligned_64 *)(left + i + 2))->l = local_pix[1]; 
        ((union unaligned_64 *)(left + i + 4))->l = local_pix[2]; 
        ((union unaligned_64 *)(left + i + 6))->l = local_pix[3];
    }
}
