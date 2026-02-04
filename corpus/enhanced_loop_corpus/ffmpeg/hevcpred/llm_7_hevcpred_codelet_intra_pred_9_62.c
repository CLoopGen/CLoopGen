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
    uint64_t local_pix[4]; // Remove dependency on global state by using local array
    for (i = 0; i < (size); i += 4) {
        // Eliminate loop-carried dependencies; all operations are independent
        local_pix[0] = pix + 0;
        local_pix[1] = pix + 1;
        local_pix[2] = pix + 2;
        local_pix[3] = pix + 3;
        ((union unaligned_64 *)(left + size + i + 0))->l = local_pix[0];
        ((union unaligned_64 *)(left + size + i + 1))->l = local_pix[1];
        ((union unaligned_64 *)(left + size + i + 2))->l = local_pix[2];
        ((union unaligned_64 *)(left + size + i + 3))->l = local_pix[3];
    }
}
