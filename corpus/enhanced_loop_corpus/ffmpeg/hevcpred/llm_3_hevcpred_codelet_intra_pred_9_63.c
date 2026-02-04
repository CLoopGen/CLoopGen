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
    // Variant 2: Strided memory access with stride of 8 instead of 4
    // Access every other target location, effectively halving the number of iterations
    // but maintaining alignment assumptions and reducing cache pressure.
    for (i = 0; i < (2 * size); i += 8) {
        ((((union unaligned_64 *)(left + i))->l) = (pix));
    }
}
