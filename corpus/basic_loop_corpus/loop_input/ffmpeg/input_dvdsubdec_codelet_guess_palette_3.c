#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *rgba_palette;
uint32_t subtitle_color;
uint8_t level_map[4][4];
uint8_t color_used[16];
int nb_opaque_colors;
int i;
int level;
int j;
int r;
int g;
int b;
uint8_t *colormap;
uint8_t *alpha;

void init_vars() {
    // Allocate 1MB for rgba_palette (262144 elements, since each is 4 bytes)
    rgba_palette = (uint32_t*)calloc(262144, sizeof(uint32_t));
    
    // Allocate 1MB for colormap and alpha (each 1MB of uint8_t => 1048576 elements)
    colormap = (uint8_t*)malloc(1048576 * sizeof(uint8_t));
    alpha = (uint8_t*)malloc(1048576 * sizeof(uint8_t));

    // Initialize subtitle_color to a non-zero value (e.g., white with full alpha)
    subtitle_color = 0xFFFFFFFF;

    // Initialize level_map with sample values to avoid undefined behavior
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            level_map[row][col] = (row * 4 + col + 1) * 16; // increasing levels
        }
    }

    // Initialize color_used array to zeros (no colors used initially)
    for (int idx = 0; idx < 16; idx++) {
        color_used[idx] = 0;
    }

    // Set nb_opaque_colors to valid value within bounds [1,4] to index level_map safely
    nb_opaque_colors = 3;

    // Initialize j to 0; it will be incremented in loop
    j = 0;

    // Initialize colormap and alpha arrays with safe test data
    for (int idx = 0; idx < 1048576; idx++) {
        // Make every 4th alpha zero to trigger both branches
        alpha[idx] = (idx % 4 == 0) ? 0 : 15 + (idx % 10);
        colormap[idx] = idx % 16; // maps to 0-15 to stay within color_used bounds
    }

    // Initialize other scalar variables used in computations
    i = 0;
    level = 0;
    r = 0;
    g = 0;
    b = 0;
}