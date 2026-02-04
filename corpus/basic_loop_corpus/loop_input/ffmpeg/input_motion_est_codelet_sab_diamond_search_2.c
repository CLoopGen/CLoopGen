#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef struct Minima {
    int height;
    int x;
    int y;
    int checked;
} Minima;

int penalty_factor = 10;
Minima minima[64];
int i;
int j;
uint32_t * score_map;
int xmin = -1024;
int ymin = -1024;
int xmax = 1024;
int ymax = 1024;
uint8_t *mv_penalty;
int pred_x = 512;
int pred_y = 512;
uint32_t *map;
int shift = 4;
unsigned int map_generation = (1 << (2 * 11));

static uint32_t *internal_score_map = NULL;
static uint8_t *internal_mv_penalty = NULL;
static uint32_t *internal_map = NULL;

void init_vars() {
    const size_t score_map_size = 64 * sizeof(uint32_t);
    internal_score_map = aligned_alloc(32, score_map_size);
    memset(internal_score_map, 0, score_map_size);
    for (int idx = 0; idx < 64; idx++) {
        internal_score_map[idx] = 1000 + idx * 7;
    }
    score_map = internal_score_map;

    const int mv_penalty_dim = (1 << 11) * 2;
    const size_t mv_penalty_size = mv_penalty_dim * sizeof(uint8_t);
    internal_mv_penalty = aligned_alloc(32, mv_penalty_size);
    memset(internal_mv_penalty, 0, mv_penalty_size);
    for (int idx = 0; idx < mv_penalty_dim; idx++) {
        internal_mv_penalty[idx] = (idx * 3) % 256;
    }
    mv_penalty = internal_mv_penalty;

    const size_t map_size = 64 * sizeof(uint32_t);
    internal_map = aligned_alloc(32, map_size);
    memset(internal_map, 0, map_size);
    for (int idx = 0; idx < 64; idx++) {
        uint32_t x = (512 + (idx % 10)) & ((1 << 11) - 1);
        uint32_t y = (512 + (idx / 10)) & ((1 << 11) - 1);
        internal_map[idx] = x | (y << 11);
    }
    map = internal_map;

    map_generation = internal_map[0] & (-(1 << (2 * 11)));
    for (int idx = 0; idx < 64; idx++) {
        if (idx % 7 == 0) {
            map[idx] = (map[idx] & ((1 << (2 * 11)) - 1)) | map_generation;
        } else {
            map[idx] = (map[idx] & ((1 << (2 * 11)) - 1)) | (map_generation ^ (1 << (2 * 11)));
        }
    }

    penalty_factor = 10;
    pred_x = 512;
    pred_y = 512;
    shift = 4;
    xmin = -1024;
    ymin = -1024;
    xmax = 1024;
    ymax = 1024;

    i = 0;
    j = 0;
}