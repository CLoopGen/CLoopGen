#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef struct A64Context {
    AVLFG randctx;
    int mc_lifetime;
    int mc_use_5col;
    unsigned int mc_frame_counter;
    int *mc_meta_charset;
    int *mc_charmap;
    int *mc_best_cb;
    int mc_luma_vals[5];
    uint8_t *mc_charset;
    uint8_t *mc_colram;
    uint8_t *mc_palette;
    int mc_pal_size;
    int64_t next_pts;
} A64Context;

uint8_t multi_dither_patterns[9][4][4] = {0};
uint8_t interlaced_dither_patterns[9][8][4] = {0};
uint8_t *charset;
uint8_t *colrammap;
A64Context *c;
uint8_t row1;
uint8_t row2;
int charpos;
int x;
int y;
uint8_t pix;
int lowdiff;
int highdiff;
int *best_cb;
uint8_t index1[256] = {0};
uint8_t index2[256] = {0};
uint8_t dither[256] = {0};

static uint8_t charset_data[256 * 8 * 2]; // 4KB for charset (2048+8 offset used)
static uint8_t colrammap_data[256];       // 256 bytes for colrammap
static int best_cb_data[256 * 32];         // 256 blocks of 32 ints

void init_vars() {
    // Allocate and initialize A64Context
    c = (A64Context*)calloc(1, sizeof(A64Context));
    if (!c) exit(1);

    // Initialize mc_luma_vals
    c->mc_luma_vals[0] = 10;
    c->mc_luma_vals[1] = 30;
    c->mc_luma_vals[2] = 64;
    c->mc_luma_vals[3] = 100;
    c->mc_luma_vals[4] = 140;

    // mc_use_5col is true to allow both branches in loop
    c->mc_use_5col = 1;

    // Setup global pointers
    charset = charset_data;
    colrammap = colrammap_data;
    best_cb = best_cb_data;

    // Initialize dither lookup: map pixel indices to pattern index
    for (int i = 0; i < 256; i++) {
        dither[i] = i % 9;
        index1[i] = i % 5;
        index2[i] = (i + 1) % 5;
    }

    // Initialize interlaced_dither_patterns and multi_dither_patterns
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                multi_dither_patterns[i][j][k] = (j + k) % 2;
                interlaced_dither_patterns[i][j*2+0][k] = (j + k) % 2;
                interlaced_dither_patterns[i][j*2+1][k] = (j + k + 1) % 2;
            }
        }
    }
}