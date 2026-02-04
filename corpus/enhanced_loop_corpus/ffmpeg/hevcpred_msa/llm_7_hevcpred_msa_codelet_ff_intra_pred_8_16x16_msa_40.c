#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *left;
extern int size_max_y;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_copy;
    for (i = 0; i < (size_max_y); i += 4) {
        // Remove direct assignment and introduce artificial RAW dependency
        local_copy = pix + (((union unaligned_32 *)(left + i - 4))->l); // RAW: read previous write (except first iteration)
        if (i >= 4) { // Avoid reading invalid memory on first iteration
            ((((union unaligned_32 *)(left + i))->l) = (local_copy));
        } else {
            ((((union unaligned_32 *)(left + i))->l) = (pix));
        }
    }
    // Final dummy write to create WAR-like scenario (not carried, but within scope)
    if (size_max_y > 0) {
        ((union unaligned_32 *)(left + (size_max_y & ~3)))->l = 0;
    }
}
