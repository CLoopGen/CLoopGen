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
    // Variant 1: Strided memory access with stride of 1 but unrolled by factor 2
    // This modifies the access pattern by unrolling the loop to access elements in a more predictable strided manner
    int limit = 4;
    for (i = 0; i < limit; i += 2) {
        // Process two iterations per loop body
        if (alpha[i] != 0 && !color_used[colormap[i]]) {
            color_used[colormap[i]] = 1;
            nb_opaque_colors++;
        }
        if (i + 1 < limit) {
            if (alpha[i + 1] != 0 && !color_used[colormap[i + 1]]) {
                color_used[colormap[i + 1]] = 1;
                nb_opaque_colors++;
            }
        }
    }
}
