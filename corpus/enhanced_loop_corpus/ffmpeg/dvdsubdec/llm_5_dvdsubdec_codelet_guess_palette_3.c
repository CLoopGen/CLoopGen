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
    for (i = 0; i < 4; i++) {
        int index = colormap[i];
        if (alpha[i] != 0 && !color_used[index]) {
            level = level_map[nb_opaque_colors - 1][j];
            r = (((subtitle_color >> 16) & 255) * level + 128) >> 8;
            g = (((subtitle_color >> 8) & 255) * level + 128) >> 8;
            b = (((subtitle_color      ) & 255) * level + 128) >> 8;
            rgba_palette[i] = b | (g << 8) | (r << 16) | ((alpha[i] * 17U) << 24);
            color_used[index] = i + 1;
            j++;
        } else if (alpha[i] != 0) {
            uint32_t prev_color = rgba_palette[color_used[index] - 1];
            rgba_palette[i] = (prev_color & 16777215) | ((alpha[i] * 17U) << 24);
        }
    }
}
