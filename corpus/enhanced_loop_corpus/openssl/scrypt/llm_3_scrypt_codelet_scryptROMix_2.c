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
    // Variant 2: Strided memory access — process every 2nd element pair, then revisit in second pass
    // Simulates a strided pattern by accessing elements with step size
    uint64_t total_elements = 32 * r;
    uint64_t stride = 2;

    // First pass: even-indexed groups
    for (i = 0; i < total_elements; i += stride) {
        uint64_t byte_offset = i * 4;
        pV = V + i;
        *pV = B[byte_offset];
        *pV |= B[byte_offset + 1] << 8;
        *pV |= B[byte_offset + 2] << 16;
        *pV |= (uint32_t)B[byte_offset + 3] << 24;
    }

    // Second pass: odd-indexed groups
    for (i = 1; i < total_elements; i += stride) {
        uint64_t byte_offset = i * 4;
        pV = V + i;
        *pV = B[byte_offset];
        *pV |= B[byte_offset + 1] << 8;
        *pV |= B[byte_offset + 2] << 16;
        *pV |= (uint32_t)B[byte_offset + 3] << 24;
    }
}
