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
    uint8_t local_used[16] = {0};
    int local_count = 0;
    for (i = 0; i < 4; i++) {
        if (alpha[i] != 0) {
            uint8_t col = colormap[i];
            if (!local_used[col]) {
                local_used[col] = 1;
                local_count++;
            }
        }
    }
    for (i = 0; i < 16; i++) {
        if (local_used[i]) {
            color_used[i] = 1;
        }
    }
    nb_opaque_colors += local_count;
}
