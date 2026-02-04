#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *left;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_pix[4]; // Remove loop-carried dependencies by using independent temporaries
    for (i = 0; i < (size); i += 4) {
        local_pix[0] = pix + 0;
        local_pix[1] = pix + 1;
        local_pix[2] = pix + 2;
        local_pix[3] = pix + 3;
        (((union unaligned_32 *)(left + size + i))->l) = local_pix[i % 4];
    }
}
