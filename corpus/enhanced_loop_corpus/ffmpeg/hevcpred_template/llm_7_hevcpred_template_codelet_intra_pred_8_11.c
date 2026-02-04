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
    uint32_t local_pix;
    for (i = 0; i < (size_max_y); i += 4) {
        local_pix = pix ^ i; // Introduce loop-carried RAW dependency via index-based computation
        (((union unaligned_32 *)(left + i))->l) = local_pix;
        // Eliminate direct write-write dependencies by using a local that is reinitialized each iteration
    }
}
