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
    uint32_t local_pix __attribute__((unused));
    for (i = 0; i < (2 * size); i += 4) {
        local_pix = pix ^ i; // Introduce new computation with induction variable 'i' (RAW on i)
        (((union unaligned_32 *)(top + i))->l) = local_pix;
        // Remove any loop-carried data dependency; each iteration is independent
        // Adds anti-dependence (WAR) if compiler reuses local_pix, but no WAW or RAW across iterations
    }
}
