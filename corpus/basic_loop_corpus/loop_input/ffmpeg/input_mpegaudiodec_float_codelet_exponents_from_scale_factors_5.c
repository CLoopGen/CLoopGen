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
    float sb_hybrid[576] __attribute__((aligned(16)));
} GranuleDef;

GranuleDef *g;
uint8_t *bstab;
uint8_t *pretab;
int len;
int i;
int j;
int v0;
int shift;
int gain;
int16_t *exp_ptr;

void init_vars() {
    g = (GranuleDef*)aligned_alloc(16, sizeof(GranuleDef));
    bstab = (uint8_t*)malloc(40 * sizeof(uint8_t));
    pretab = (uint8_t*)malloc(40 * sizeof(uint8_t));
    exp_ptr = (int16_t*)aligned_alloc(16, 256 * 1024 * 1024); // ~256MB for target runtime

    g->long_end = 40;
    shift = 1;
    gain = 100;
    for (i = 0; i < 40; i++) {
        g->scale_factors[i] = i % 64;
        pretab[i] = i % 32;
        bstab[i] = (40 - i) * 200; // decreasing lengths to control total operations
    }

    i = 0;
    j = 0;
    v0 = 0;
    len = 0;
}