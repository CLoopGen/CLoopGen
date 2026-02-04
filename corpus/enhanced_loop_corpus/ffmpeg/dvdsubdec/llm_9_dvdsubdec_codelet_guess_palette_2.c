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
    int limit = nb_opaque_colors < 2 ? 2 : 6;
    for (i = 0; i < limit && i < 16; i++) {
        if (alpha[i] == 255) {
            if (!color_used[colormap[i]]) {
                color_used[colormap[i]] = 1;
                nb_opaque_colors += 1;
            }
        } else if (alpha[i] > 128 && i % 2 == 0) {
            uint8_t col = colormap[i];
            if (!color_used[col]) {
                color_used[col] = 1;
                nb_opaque_colors += 1;
            }
        }
    }
}
