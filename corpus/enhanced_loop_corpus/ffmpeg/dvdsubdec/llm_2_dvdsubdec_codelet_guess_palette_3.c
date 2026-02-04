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
    // Variant 1: Consecutive memory access pattern with reordered computation
    // Arrays are accessed in increasing order with no branching in strides.
    // We precompute colormap index to ensure linear traversal potential.
    uint8_t *cm = colormap;
    uint32_t *pal = rgba_palette;
    uint8_t *a = alpha;
    uint8_t *cu = color_used;
    int opq_level_base = nb_opaque_colors - 1;

    for (i = 0; i < 4; i++) {
        if (a[i]) {
            int idx = cm[i];
            if (!cu[idx]) {
                level = level_map[opq_level_base][j];
                r = (((subtitle_color >> 16) & 255) * level) >> 8;
                g = (((subtitle_color >>  8) & 255) * level) >> 8;
                b = (( subtitle_color         & 255) * level) >> 8;
                pal[i] = b | (g << 8) | (r << 16) | ((a[i] * 17U) << 24);
                cu[idx] = i + 1;
                j++;
            } else {
                pal[i] = (pal[cu[idx] - 1] & 16777215) | ((a[i] * 17U) << 24);
            }
        }
    }
}
