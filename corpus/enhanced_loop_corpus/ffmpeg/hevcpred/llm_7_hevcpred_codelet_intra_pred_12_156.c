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
    uint64_t local_pix[4]; // Remove loop-carried dependency by using local independent values
    for (i = 0; i < (size); i += 4) {
        // Introduce data independence: each element computed without relying on prior iterations
        local_pix[0] = pix;
        local_pix[1] = pix + 1;
        local_pix[2] = pix + 2;
        local_pix[3] = pix + 3;
        ((union unaligned_64 *)(top + i))->l = local_pix[0];
    }
}
