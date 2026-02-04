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
    // Variant 2: Strided access with increased stride and reduced iterations
    // Access memory with a larger stride (skip more elements), simulating sparse update pattern.
    // This variant accesses every other target location from the original, effectively halving writes.
    for (i = 0; i < (2 * size); i += 8) {
        (((union unaligned_64 *)(left + i))->l) = pix;
    }
}
