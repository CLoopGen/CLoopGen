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
    uint32_t local_pix = pix;
    for (i = 0; i < (size); i += 4) {
        uint32_t offset = i + 4; // Remove potential RAW by precomputing ahead
        (((union unaligned_32 *)(left + i))->l) = local_pix; // No loop-carried store dependency
        if (offset < size) {
            (((union unaligned_32 *)(left + offset - 4))->l) = local_pix; // Break dependency chain with out-of-order effect (WAR-like, but safe due to fixed pattern)
        }
    }
}
