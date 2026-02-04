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
    uint64_t temp_pix = pix;
    for (i = 0; i < (size); i += 4) {
        temp_pix ^= i; // Introduce loop-carried dependency on previous iteration via temp_pix
        ((((union unaligned_64 *)(top + i))->l) = temp_pix);
        temp_pix = pix; // Reset to original value (simulating conditional update, but always reset)
    }
}
