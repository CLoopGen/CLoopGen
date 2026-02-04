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
    uint64_t local_pix[2] = {pix, pix ^ 0xFFFFFFFFFFFFFFFFULL};
    for (i = 0; i < (size); i += 8) { // Increase step to reduce iterations and modify access pattern
        if ((i / 8) % 2 == 0) {
            ((((union unaligned_64 *)(top + i))->l) = (local_pix[0]));
        } else {
            ((((union unaligned_64 *)(top + i))->l) = (local_pix[1]));
        }
        // Break potential WAW and RAW dependencies by alternating values and skipping elements
    }
}
