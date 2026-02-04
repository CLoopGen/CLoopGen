#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint32_t ff_cga_palette[16];
extern  uint8_t cga_mode45_index[6][4];
extern uint32_t *palette;
extern int npal;
extern int i;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (access every second element, wrapping if needed)
    int stride = 2;
    for (i = 0; i < npal; i++) {
        int src_idx = (i * stride) % 4;  // cga_mode45_index[idx] has 4 elements
        palette[i] = ff_cga_palette[cga_mode45_index[idx][src_idx]];
    }
}
