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
for (i = 0; i < 4; i += 2) {
    if (alpha[i] != 0) {
        if (!color_used[colormap[i]]) {
            level = level_map[nb_opaque_colors - 1][j];
            r = ((subtitle_color >> 16) & 255);
            g = ((subtitle_color >> 8) & 255);
            b = (subtitle_color & 255);
            r = (r * level) >> 8;
            g = (g * level) >> 8;
            b = (b * level) >> 8;
            rgba_palette[i] = b | (g << 8) | (r << 16) | ((alpha[i] * 17U) << 24);
            color_used[colormap[i]] = (i + 1);
            j++;
        } else {
            rgba_palette[i] = (rgba_palette[color_used[colormap[i]] - 1] & 16777215) | ((alpha[i] * 17U) << 24);
        }
    }
    if (i + 1 < 4 && alpha[i + 1] != 0) {
        if (!color_used[colormap[i + 1]]) {
            level = level_map[nb_opaque_colors - 1][j];
            r = (((subtitle_color >> 16) & 255) * level) >> 8;
            g = (((subtitle_color >> 8) & 255) * level) >> 8;
            b = ((subtitle_color & 255) * level) >> 8;
            rgba_palette[i + 1] = b | (g << 8) | (r << 16) | ((alpha[i + 1] * 17U) << 24);
            color_used[colormap[i + 1]] = (i + 2);
            j++;
        } else {
            rgba_palette[i + 1] = (rgba_palette[color_used[colormap[i + 1]] - 1] & 16777215) | ((alpha[i + 1] * 17U) << 24);
        }
    }
}
}
