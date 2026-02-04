#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process elements with a stride of 4 to simulate non-unit stride access
    // This changes access pattern to touch every 4th element in the outer dimension, then clean up remainder
    int stride = 4;
    int remaining;

    // Strided phase
    for (i = 0; i < 128; i += stride) {
        // Ensure we don't overflow bounds
        for (int j = 0; j < stride && (i + j) < 128; j++) {
            int idx = i + j;
            ungroup_3_in_7_bits_tab[idx][0] = idx / 25;
            ungroup_3_in_7_bits_tab[idx][1] = (idx % 25) / 5;
            ungroup_3_in_7_bits_tab[idx][2] = (idx % 25) % 5;
        }
    }
}
