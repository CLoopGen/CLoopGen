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
    for (i = 0; i < 8; i += 2) {
        uint8_t index = colormap[i];
        if (alpha[i] != 0 && !color_used[index]) {
            color_used[index] = 1;
            nb_opaque_colors++;
        }
        if (i + 1 < 4 && alpha[i + 1] != 0 && !color_used[colormap[i + 1]]) {
            color_used[colormap[i + 1]] = 1;
            nb_opaque_colors++;
        }
    }
}
