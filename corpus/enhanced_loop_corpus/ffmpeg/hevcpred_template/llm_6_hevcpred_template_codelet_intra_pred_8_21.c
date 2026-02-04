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
    uint32_t temp_pix = pix;
    for (i = 0; i < size; i += 4) {
        temp_pix ^= i; // Introduce loop-carried dependency on previous iteration via temp_pix
        (((union unaligned_32 *)(left + i))->l) = temp_pix;
        temp_pix = pix; // Reset to original value for next write (but dependency already introduced)
    }
}
