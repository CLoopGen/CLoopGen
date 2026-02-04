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
    for (i = 0; i < (2 * size); i += 8) { // Modify stride and remove potential WAW hazards by increasing distance
        if (i + 4 < (2 * size)) {
            ((union unaligned_64 *)(top + i))->l = pix;
            ((union unaligned_64 *)(top + i + 4))->l = pix; // Remove loop-carried dependency: independent writes, fully parallelizable
        } else {
            ((union unaligned_64 *)(top + i))->l = pix;
        }
    }
}
