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
    // Variant 2: Strided memory access with increasing stride to simulate non-contiguous pattern
    int stride = 4;
    for (i = 0; i < (2 * size); i += stride * 2) {
        int index = (i / (stride * 2)) * stride; // Create strided index progression
        if (index < (2 * size - 3)) {
            (((union unaligned_64 *)(left + index))->l) = pix;
        }
    }
}
