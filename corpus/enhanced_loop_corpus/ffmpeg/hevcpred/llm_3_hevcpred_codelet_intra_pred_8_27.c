#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive 32-bit writes using byte offset progression, unrolling by 2 for consecutive access
    for (i = 0; i < (size - 3); i += 4) {
        ((((union unaligned_32 *)(top + i))->l) = (pix));
        if (i + 4 < size)
            ((((union unaligned_32 *)(top + i + 4))->l) = (pix));
    }
}
