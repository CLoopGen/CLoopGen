#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *rgba_palette;
extern uint32_t subtitle_color;
extern  uint8_t level_map[4][4];
extern uint8_t color_used[16];
extern int nb_opaque_colors;
extern int i;
extern int level;
extern int j;
extern int r;
extern int g;
extern int b;
extern uint8_t *colormap;
extern uint8_t *alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided and indirect memory access using pointer arithmetic with fixed stride of 2
    // Simulates non-unit stride access; accesses every other element in a virtual expanded space
    // Note: Still covers all 4 iterations but via strided indexing pattern mapped logically
    uint8_t indices[4] = {0, 2, 1, 3}; // arbitrary permutation to simulate irregular access intent
    uint32_t *pal = rgba_palette;
    uint8_t *a = alpha;
    uint8_t *cm = colormap;
    uint8_t *cu = color_used;

    for (i = 0; i < 4; i++) {
        int k = indices[i]; // Indirect access via lookup index
        if (a[k]) {
            int cidx = cm[k];
            if (!cu[cidx]) {
                level = level_map[nb_opaque_colors - 1][j];
                r = (((subtitle_color >> 16) & 255) * level) >> 8;
                g = (((subtitle_color >> 8) & 255) * level) >> 8;
                b = (((subtitle_color      ) & 255) * level) >> 8;
                pal[k] = b | (g << 8) | (r << 16) | ((a[k] * 17U) << 24);
                cu[cidx] = k + 1;
                j++;
            } else {
                pal[k] = (pal[cu[cidx] - 1] & 16777215) | ((a[k] * 17U) << 24);
            }
        }
    }
}
