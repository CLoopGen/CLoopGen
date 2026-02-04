#include <stdio.h>

#include <inttypes.h>

extern unsigned char *B;
extern uint64_t r;
extern uint32_t *V;
extern unsigned char *pB;
extern uint32_t *pV;
extern uint64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing (instead of pointer arithmetic)
    for (i = 0; i < 32 * r; i++) {
        uint64_t base_index = i * 4;
        pV = V + i;
        *pV = B[base_index];
        *pV |= B[base_index + 1] << 8;
        *pV |= B[base_index + 2] << 16;
        *pV |= (uint32_t)B[base_index + 3] << 24;
    }
}
