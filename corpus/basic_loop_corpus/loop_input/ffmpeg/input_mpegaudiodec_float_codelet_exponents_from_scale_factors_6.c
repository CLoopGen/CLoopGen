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
    // Allocate and initialize g
    g = (GranuleDef*)aligned_alloc(16, sizeof(GranuleDef));
    g->short_start = 5;  // Ensure loop runs from 5 to 12 (8 iterations)
    g->long_end = 0;
    for (int idx = 0; idx < 40; idx++) {
        g->scale_factors[idx] = rand() % 128;
    }

    // Initialize bstab: needs at least 13 entries (index 0 to 12)
    bstab = (uint8_t*)malloc(13 * sizeof(uint8_t));
    for (int idx = 0; idx < 13; idx++) {
        bstab[idx] = 8;  // Each inner loop runs 8 times
    }

    // Initialize shift and gains
    shift = 2;
    gains[0] = 100;
    gains[1] = 200;
    gains[2] = 300;

    // Estimate total operations: 
    // Outer loop: 13 - short_start = 8 iterations
    // Middle loop: 3 iterations
    // Inner loop: bstab[i] = 8 -> 8 * 3 * 8 = 192 per outer i -> 8 * 192 = 1536 total writes
    // To make loop take ~0.01s, we need more data. Scale up exp_ptr size accordingly.
    // Assume ~1e8 operations per second -> ~1e6 operations in 0.01s.
    // We currently have ~1536 operations. Scale up the length values.

    // Let's increase bstab values and adjust allocation accordingly.
    // Reinitialize bstab with larger values to meet data size target.
    free(bstab);
    bstab = (uint8_t*)malloc(13 * sizeof(uint8_t));
    const int base_len = 1024;  // Increase inner loop length
    for (int idx = 0; idx < 13; idx++) {
        bstab[idx] = base_len;
    }

    // Total memory written: (13 - short_start) * 3 * base_len = 8 * 3 * 1024 = 24,576 elements
    // To reach ~1MB–256MB of data, scale further.
    // Target: ~16M elements (approx 32MB for int16_t)
    // So we want: (13-short_start) * 3 * len_avg = ~16M => len_avg ~ 16M / 24 = ~65536
    const int scaled_len = 65536;
    for (int idx = 0; idx < 13; idx++) {
        bstab[idx] = scaled_len;
    }

    // Now total writes: 8 * 3 * 65536 = 1,572,864 (~1.5 million), which should take ~0.01s
    // Allocate exp_ptr with sufficient space
    size_t total_size = (13 - g->short_start) * 3 * scaled_len;
    exp_ptr = (int16_t*)malloc(total_size * sizeof(int16_t));
    k = 0;  // Will be used as index into scale_factors, reset during loop

    // Ensure k does not overflow scale_factors (size 40)
    // Total increments to k: (13 - short_start) * 3 = 8 * 3 = 24 -> safe (k from 0 to 23)
}