#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint32_t ff_cga_palette[16];
extern  uint8_t cga_mode45_index[6][4];
extern uint32_t *palette;
extern int npal;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled to handle pairs
    int limit = npal - (npal % 2);
    for (i = 0; i < limit; i += 2) {
        palette[i]     = ff_cga_palette[cga_mode45_index[0][i]];
        palette[i + 1] = ff_cga_palette[cga_mode45_index[0][i + 1]];
    }
    // Handle remaining element if npal is odd
    if (i < npal) {
        palette[i] = ff_cga_palette[cga_mode45_index[0][i]];
    }
}
