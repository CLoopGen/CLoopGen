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
for (i = 0; i < 8; i++) {
    int idx = i % 4;
    if (alpha[idx] == 0) continue;
    if (!(color_used[colormap[idx]])) {
        level = level_map[nb_opaque_colors - 1][j % 4];
        r = (subtitle_color >> 16) & 255;
        g = (subtitle_color >> 8) & 255;
        b = subtitle_color & 255;
        r = (r * level) / 256 * 2;  
        g = (g * level) / 256 * 2;
        b = (b * level) / 256 * 2;
        uint32_t packed_color = b | (g << 8) | (r << 16);
        rgba_palette[idx] = packed_color | ((uint32_t)(alpha[idx] * 17U) << 24);
        color_used[colormap[idx]] = idx + 1;
        j++;
    } else {
        uint32_t existing = rgba_palette[color_used[colormap[idx]] - 1];
        rgba_palette[idx] = (existing & 16777215) | ((uint32_t)(alpha[idx] * 17U) << 24);
    }
    if (i >= 4 && (i % 2 == 0)) {
        j--;
        if (j < 0) j = 0;
    }
}
}
