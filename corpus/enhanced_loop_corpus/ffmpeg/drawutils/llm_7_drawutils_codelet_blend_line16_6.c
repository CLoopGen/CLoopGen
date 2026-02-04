#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst;
extern int dx;
extern int w;
extern unsigned int asrc;
extern unsigned int tau;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint16_t buffer[2] = {0}; // Local storage to break direct memory dependencies
    for (x = 0; x < w; x++) {
        uint16_t value = (((const union unaligned_16 *)(local_dst))->l);
        uint16_t result = (value * tau + asrc) >> 16;
        buffer[x & 1] = result; // Break WAW dependency using modulo indexing
        ((((union unaligned_16 *)(local_dst))->l) = buffer[x & 1]);
        local_dst += dx;
    }
    // Final use of buffer to prevent dead code elimination
    dst += dx * w;
}
