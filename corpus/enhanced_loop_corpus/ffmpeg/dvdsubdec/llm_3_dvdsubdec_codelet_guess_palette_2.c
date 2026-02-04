#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t color_used[16];
extern int nb_opaque_colors;
extern int i;
extern uint8_t *colormap;
extern uint8_t *alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate indirect addressing
    // This changes the access pattern from direct sequential to indirect via an index map
    uint8_t indices[4] = {0, 1, 2, 3}; // Simulate indirect access order
    for (i = 0; i < 4; i++) {
        uint8_t idx = indices[i]; // Use indirection
        if (alpha[idx] != 0 && !color_used[colormap[idx]]) {
            color_used[colormap[idx]] = 1;
            nb_opaque_colors++;
        }
    }
}
