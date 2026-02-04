#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t color_used[16];
int nb_opaque_colors;
int i;
uint8_t *colormap;
uint8_t *alpha;

void init_vars() {
    colormap = (uint8_t *)malloc(4 * sizeof(uint8_t));
    alpha = (uint8_t *)malloc(4 * sizeof(uint8_t));

    if (!colormap || !alpha) {
        exit(1);
    }

    for (i = 0; i < 4; i++) {
        colormap[i] = rand() % 16;
        alpha[i] = rand() % 256;
    }

    memset(color_used, 0, 16 * sizeof(uint8_t));
    nb_opaque_colors = 0;
}