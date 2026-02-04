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
uint8_t *pretab;
int len;
int i;
int j;
int v0;
int shift;
int gain;
int16_t *exp_ptr;

static GranuleDef g_storage;
static uint8_t bstab_storage[40];
static uint8_t pretab_storage[40];
static int16_t exp_ptr_storage[1 << 20];

void init_vars() {
    g = &g_storage;
    bstab = bstab_storage;
    pretab = pretab_storage;
    exp_ptr = exp_ptr_storage;

    g->long_end = 40;
    g->global_gain = 100;
    shift = 2;
    gain = 200;

    for (int idx = 0; idx < 40; idx++) {
        g->scale_factors[idx] = rand() % 64;
        pretab[idx] = rand() % 16;
        bstab[idx] = rand() % 256;
    }

    for (int idx = 0; idx < (int)(1 << 20); idx++) {
        exp_ptr_storage[idx] = 0;
    }

    len = 0;
    i = 0;
    j = 0;
    v0 = 0;
}