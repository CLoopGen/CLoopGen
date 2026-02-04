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
    uint64_t local_pix[4];
    // Break aliasing and remove potential WAW/WAR hazards by precomputing independent values
    for (int j = 0; j < 4; j++) {
        local_pix[j] = pix ^ (j + 1); // Remove loop-carried dependency, fully data-independent
    }
    for (i = 0; i < (size); i += 4) {
        ((((union unaligned_64 *)(top + i))->l) = local_pix[0]);
        if (i + 4 < size) {
            ((((union unaligned_64 *)(top + i + 4))->l) = local_pix[1]); // Overlap store operations without dependency
        }
    }
}
