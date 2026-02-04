#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
    // Allocate and initialize bstab: needs at least 13 entries
    bstab = (uint8_t*)malloc(13 * sizeof(uint8_t));
    for (int idx = 0; idx < 13; idx++) {
        bstab[idx] = 8; // Each inner loop runs 8 times
    }

    // Allocate g and initialize relevant fields
    g = (GranuleDef*)malloc(sizeof(GranuleDef));
    g->short_start = 0; // Start from 0 to run 13 iterations
    g->long_end = 0;
    g->scalefac_scale = 0;
    g->count1table_select = 0;
    g->preflag = 0;
    g->part2_3_length = 0;
    g->big_values = 0;
    g->global_gain = 100;
    g->scalefac_compress = 0;
    g->block_type = 0;
    g->switch_point = 0;
    for (int idx = 0; idx < 3; idx++) {
        g->table_select[idx] = 0;
        g->subblock_gain[idx] = 0;
        g->region_size[idx] = 0;
    }
    for (int idx = 0; idx < 40; idx++) {
        g->scale_factors[idx] = 1; // Avoid zero shifts
    }
    for (int idx = 0; idx < 576; idx++) {
        g->sb_hybrid[idx] = 0;
    }

    // Set shift and gains
    shift = 2;
    gains[0] = 100;
    gains[1] = 120;
    gains[2] = 140;

    // Allocate exp_ptr buffer: total writes = (13 - short_start) * 3 * bstab[i]
    // With short_start=0, 13*3*8 = 312 per outer iteration, but k increments across all
    // Total k usage: 13 * 3 = 39 scale_factors used -> safe since we have 40
    // Total exp_ptr writes: 13 * 3 * 8 = 312
    // To make it heavier, replicate the pattern to increase data size
    // Target ~100MB of output: each write is 2 bytes (int16_t)
    // 100MB = 50M elements. We currently do 312 per full loop.
    // So repeat the entire loop about 50M / 312 ≈ 160,256 times
    const int repeat_factor = 160256;
    const int total_size = 13 * 3 * 8 * repeat_factor;
    exp_ptr = (int16_t*)malloc(total_size * sizeof(int16_t));
    if (!exp_ptr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    // Reset exp_ptr to beginning for loop to fill
    int16_t* base_exp_ptr = exp_ptr;

    // Re-initialize variables that will be used in loop
    len = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    v0 = 0;

    // Simulate repeated execution setup without running the loop yet
    // Just reset exp_ptr to start
    exp_ptr = base_exp_ptr;

    // Adjust short_start to allow full range
    g->short_start = 0;
}