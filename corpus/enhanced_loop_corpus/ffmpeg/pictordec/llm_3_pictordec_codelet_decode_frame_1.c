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
    // Variant 2: Indirect memory access using an index remapping array (simulated via fixed permutation)
    // Assume indirect addressing through a static permutation for diversity in access pattern
    static const uint8_t indices[16] = {0,2,4,6,8,10,12,14,1,3,5,7,9,11,13,15}; // Interleaved even-odd order
    for (i = 0; i < npal; i++) {
        int idx = indices[i]; // Indirect access index
        if (idx < 4) { // Ensure within bounds of cga_mode45_index[0][0..3]
            palette[i] = ff_cga_palette[cga_mode45_index[0][idx]];
        } else {
            palette[i] = ff_cga_palette[cga_mode45_index[0][0]]; // fallback, though npal should be <=4
        }
    }
}
