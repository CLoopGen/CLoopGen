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
int i;
int k;
int j;

void init_vars() {
    g = (GranuleDef*)aligned_alloc(16, sizeof(GranuleDef));
    if (!g) exit(1);

    g->scfsi = 1;
    g->part2_3_length = 500;
    g->big_values = 300;
    g->global_gain = 80;
    g->scalefac_compress = 5;
    g->block_type = 2;
    g->switch_point = 1;
    g->table_select[0] = 1; g->table_select[1] = 2; g->table_select[2] = 3;
    g->subblock_gain[0] = 4; g->subblock_gain[1] = 3; g->subblock_gain[2] = 2;
    g->scalefac_scale = 1;
    g->count1table_select = 0;
    g->region_size[0] = 100;
    g->region_size[1] = 200;
    g->region_size[2] = 250;
    g->preflag = 0;
    g->short_start = 50;
    g->long_end = 150;

    for (int idx = 0; idx < 40; idx++) {
        g->scale_factors[idx] = idx % 16;
    }

    for (int idx = 0; idx < 576; idx++) {
        g->sb_hybrid[idx] = 1.0f;
    }

    i = 0;
    k = 0;
    j = 0;
}