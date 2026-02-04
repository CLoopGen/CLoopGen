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
    uint32_t temp_palette[4] = {0}; // Introduce local accumulation to alter WAW and RAW dependencies
    int local_used[16] = {0};       // Remove loop-carried dependency on global color_used
    j = 0; // Reset j locally to eliminate external dependency

    for (i = 0; i < 4; i++) {
        if (alpha[i] != 0) {
            int idx = colormap[i];
            if (!local_used[idx]) {
                int level = level_map[nb_opaque_colors - 1][j];
                r = (((subtitle_color >> 16) & 255) * level) >> 8;
                g = (((subtitle_color >> 8) & 255) * level) >> 8;
                b = (((subtitle_color >> 0) & 255) * level) >> 8;
                temp_palette[i] = b | (g << 8) | (r << 16) | ((alpha[i] * 17U) << 24);
                local_used[idx] = i + 1;
                j++;
            } else {
                temp_palette[i] = (temp_palette[local_used[idx] - 1] & 16777215) | ((alpha[i] * 17U) << 24);
            }
        }
    }

    // Write back to global state only after full computation (eliminates WAW hazards during loop)
    for (i = 0; i < 4; i++) {
        rgba_palette[i] = temp_palette[i];
    }
    // Update global color_used from local copy to break intra-loop write-read dependency
    for (int k = 0; k < 16; k++) {
        if (local_used[k]) {
            color_used[k] = local_used[k];
        }
    }
}
