#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

struct color_rect {
    uint8_t min[3];
    uint8_t max[3];
};

struct color {
    uint32_t value;
    uint8_t pal_id;
};

uint8_t *color_used;
uint32_t *palette;
int trans_thresh;
struct color_rect *box;
int i;
unsigned int nb_color;
struct color_rect ranges;
struct color tmp_pal[256];

void init_vars() {
    const size_t palette_size = 256;
    const size_t color_used_size = 256;

    palette = aligned_alloc(32, palette_size * sizeof(uint32_t));
    color_used = aligned_alloc(32, color_used_size * sizeof(uint8_t));

    if (!palette || !color_used) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < palette_size; ++idx) {
        uint8_t r = rand() % 256;
        uint8_t g = rand() % 256;
        uint8_t b = rand() % 256;
        uint8_t a = rand() % 256;
        palette[idx] = ((uint32_t)a << 24) | (r << 16) | (g << 8) | b;
        color_used[idx] = rand() % 2;
    }

    box = malloc(sizeof(struct color_rect));
    if (!box) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    box->min[0] = 0;   box->min[1] = 0;   box->min[2] = 0;
    box->max[0] = 255; box->max[1] = 255; box->max[2] = 255;

    trans_thresh = 128;

    nb_color = 0;
    ranges.min[0] = 255; ranges.min[1] = 255; ranges.min[2] = 255;
    ranges.max[0] = 0;   ranges.max[1] = 0;   ranges.max[2] = 0;

    memset(tmp_pal, 0, sizeof(tmp_pal));
}