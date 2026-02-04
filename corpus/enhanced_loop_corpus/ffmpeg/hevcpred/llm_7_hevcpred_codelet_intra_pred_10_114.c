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
    for (i = 0; i < (size); i += 4) {
        uint64_t local_pix = pix + ((uint64_t)i << 32); // Eliminate potential WAW/WAR by using local computation
        (((union unaligned_64 *)(top + size + i))->l) = local_pix;
        // Remove any data dependency between iterations — fully parallelizable now
    }
}
