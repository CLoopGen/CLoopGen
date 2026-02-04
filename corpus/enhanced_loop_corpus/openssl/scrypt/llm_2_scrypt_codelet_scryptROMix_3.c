#include <stdio.h>

#include <inttypes.h>

extern unsigned char *B;
extern uint64_t r;
extern uint32_t *X;
extern unsigned char *pB;
extern uint64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of writing 4 consecutive bytes per X[i], write in a strided manner
    // where each byte goes to positions separated by a stride of 4.
    // This transforms the output layout into a structure-of-arrays style for interleaved components.
    uint64_t total_elements = 32 * r;
    unsigned char *base_pB = pB;
    for (i = 0; i < total_elements; i++) {
        uint32_t xtmp = X[i];
        base_pB[i]           = xtmp & 255;
        base_pB[i + total_elements]     = (xtmp >> 8) & 255;
        base_pB[i + 2*total_elements]   = (xtmp >> 16) & 255;
        base_pB[i + 3*total_elements]   = (xtmp >> 24) & 255;
    }
    // Update pB to point past the last written element
    pB += 4 * total_elements;
}
