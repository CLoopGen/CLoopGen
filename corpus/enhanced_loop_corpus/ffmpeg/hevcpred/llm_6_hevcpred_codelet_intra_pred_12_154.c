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
    uint64_t temp_pix = pix;
    for (i = 0; i < (2 * size); i += 4) {
        (((union unaligned_64 *)(left + i))->l) = temp_pix;
        temp_pix ^= ((union unaligned_64 *)(left + i))->l; // Introduce RAW and WAW: read after write, then modify temp_pix based on it
    }
}
