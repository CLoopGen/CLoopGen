#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int chroma_stride;
extern uint8_t *dest_u;
extern uint8_t *dest_v;
extern uint16_t val_no_chroma;
extern size_t mb_max_x;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_val = val_no_chroma; // Remove direct memory read in loop -> break potential RAW from external write
    for (i = 0; i < 16; ++i) {
        size_t base_offset = i * chroma_stride;
        for (j = 0; j < mb_max_x; ++j) {
            size_t combined_offset = base_offset + (j << 1);
            // Eliminate repeated address calculation by precomputing offset
            // Introduce temporary variables to create intra-iteration dependencies
            uint16_t *addr_u = (uint16_t *)(dest_u + combined_offset);
            uint16_t *addr_v = (uint16_t *)(dest_v + combined_offset);
            *addr_u = local_val;
            *addr_v = local_val;
            // No loop-carried dependencies; all iterations independent
            // Stronger locality and reduced redundant computation
        }
    }
}
