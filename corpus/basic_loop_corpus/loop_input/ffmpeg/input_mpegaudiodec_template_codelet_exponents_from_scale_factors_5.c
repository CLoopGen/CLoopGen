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
uint8_t *pretab;
int len;
int i;
int j;
int v0;
int shift;
int gain;
int16_t *exp_ptr;

void init_vars() {
    // Allocate g and initialize long_end to a safe value within scale_factors bounds
    g = (GranuleDef*)calloc(1, sizeof(GranuleDef));
    g->long_end = 40;  // Must not exceed scale_factors array size (40)

    // Allocate bstab and pretab arrays of size at least g->long_end
    bstab = (uint8_t*)calloc(g->long_end, sizeof(uint8_t));
    pretab = (uint8_t*)calloc(g->long_end, sizeof(uint8_t));

    // Initialize bstab with small values to control inner loop iterations
    for (int idx = 0; idx < g->long_end; idx++) {
        bstab[idx] = 4;  // Each inner loop runs 4 times
        pretab[idx] = idx % 32;
    }

    // Set shift and gain to reasonable values
    shift = 1;
    gain = 100;

    // Calculate total number of writes: sum of bstab[0..long_end-1]
    size_t total_writes = 0;
    for (int idx = 0; idx < g->long_end; idx++) {
        total_writes += bstab[idx];
    }

    // Allocate exp_ptr buffer large enough to avoid overflow
    // Aim for ~64M operations to take ~0.01s on modern CPU
    const size_t target_writes = 16 * 1024 * 1024; // ~16 million writes
    const size_t multiplier = target_writes / (total_writes + 1) + 1;

    // Scale long_end and reallocate accordingly
    g->long_end = 40;
    free(bstab);
    free(pretab);
    bstab = (uint8_t*)calloc(g->long_end, sizeof(uint8_t));
    pretab = (uint8_t*)calloc(g->long_end, sizeof(uint8_t));

    total_writes = 0;
    for (int idx = 0; idx < g->long_end; idx++) {
        bstab[idx] = 4 * multiplier;  // Scale up to meet target
        pretab[idx] = idx % 32;
        total_writes += bstab[idx];
    }

    // Reallocate exp_ptr to hold all writes
    exp_ptr = (int16_t*)calloc(total_writes, sizeof(int16_t));
}