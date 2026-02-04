#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct GranuleDef {
    uint8_t scfsi;
    int part2_3_length;
    int big_values;
    int global_gain;
    int scalefac_compress;
    uint8_t block_type;
    uint8_t switch_point;
    int table_select[3];
    int subblock_gain[3];
    uint8_t scalefac_scale;
    uint8_t count1table_select;
    int region_size[3];
    int preflag;
    int short_start;
    int long_end;
    uint8_t scale_factors[40];
    int sb_hybrid[576] __attribute__((aligned(16)));
} GranuleDef;

GranuleDef *g;
uint8_t *bstab;
int len;
int i;
int j;
int k;
int l;
int v0;
int shift;
int gains[3];
int16_t *exp_ptr;

void init_vars() {
    bstab = (uint8_t*)aligned_alloc(16, 13 * sizeof(uint8_t));
    for (int idx = 0; idx < 13; idx++) {
        bstab[idx] = 8;
    }

    g = (GranuleDef*)aligned_alloc(16, sizeof(GranuleDef));
    g->short_start = 0;
    g->long_end = 12;
    k = 0;
    for (int idx = 0; idx < 40; idx++) {
        g->scale_factors[idx] = idx % 25;
    }
    shift = 2;

    gains[0] = 100;
    gains[1] = 200;
    gains[2] = 300;

    size_t total_exp_size = 0;
    for (int idx = g->short_start; idx < 13; idx++) {
        int len_val = bstab[idx];
        total_exp_size += len_val * 3;
    }
    exp_ptr = (int16_t*)aligned_alloc(16, total_exp_size * sizeof(int16_t));
}