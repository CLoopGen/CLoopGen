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
extern int top_right_size;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_pix[4];
    for (i = 0; i < (size - top_right_size); i += 4) {
        // Remove direct dependency on global 'pix' by using a locally computed value independent of loop iterations
        local_pix[0] = pix + 1;
        local_pix[1] = pix + 2;
        local_pix[2] = pix + 3;
        local_pix[3] = pix + 4;
        ((((union unaligned_64 *)(top + size + top_right_size + i))->l) = local_pix[i % 4]);
    }
}
