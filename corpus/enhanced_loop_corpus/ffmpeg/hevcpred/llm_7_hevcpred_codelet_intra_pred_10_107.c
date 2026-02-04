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
    uint64_t local_pix = pix;
    for (i = 0; i < (2 * size); i += 4) {
        uint64_t computed_val = local_pix + ((uint64_t)i << 32); // Break WAW and WAR dependencies by using local computation
        (((union unaligned_64 *)(left + i))->l) = computed_val;
        // No write to shared state beyond memory store; no loop-carried data dependency
    }
}
