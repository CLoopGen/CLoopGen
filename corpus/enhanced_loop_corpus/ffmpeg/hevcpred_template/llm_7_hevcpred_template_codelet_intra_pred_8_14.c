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
    uint32_t local_copy;
    for (i = 0; i < (size); i += 4) {
        // Eliminate direct use of global 'pix' in memory write by introducing a local computation (RAW dependency on i)
        local_copy = pix + i; // Introduce new data dependency on loop index (non-loop-carried, per-iteration independent)
        ((((union unaligned_32 *)(left + size + i))->l) = (local_copy));
        // No loop-carried dependency; each iteration is independent
    }
}
