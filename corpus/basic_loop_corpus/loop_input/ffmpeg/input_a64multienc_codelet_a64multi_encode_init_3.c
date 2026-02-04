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

uint8_t a64_palette[16][3] = {
    {0, 0, 0},
    {0, 0, 170},
    {0, 170, 0},
    {0, 170, 170},
    {170, 0, 0},
    {170, 0, 170},
    {170, 85, 0},
    {170, 170, 170},
    {85, 85, 85},
    {85, 85, 255},
    {85, 255, 85},
    {85, 255, 255},
    {255, 85, 85},
    {255, 85, 255},
    {255, 255, 85},
    {255, 255, 255}
};

uint8_t mc_colors[5] = {1, 3, 5, 7, 9};

A64Context *c;
int a;

static int internal_mc_pal_size = 5;
static uint8_t *internal_mc_palette = NULL;

void init_vars() {
    // Allocate enough data to make loop take ~0.01s (though this loop is very short)
    // Since the loop runs only mc_pal_size times (5), we don't need large data
    // But ensure all pointers are valid
    
    if (internal_mc_palette == NULL) {
        internal_mc_palette = (uint8_t*)calloc(1, 256);
    }
    
    c = (A64Context*)calloc(1, sizeof(A64Context));
    c->mc_pal_size = internal_mc_pal_size;
    c->mc_palette = internal_mc_palette;
    
    // Initialize randctx.state to avoid uninitialized memory issues
    for (int i = 0; i < 64; i++) {
        c->randctx.state[i] = i;
    }
    c->randctx.index = 0;
    
    c->mc_lifetime = 100;
    c->mc_use_5col = 1;
    c->mc_frame_counter = 0;
    c->mc_meta_charset = (int*)calloc(256, sizeof(int));
    c->mc_charmap = (int*)calloc(256, sizeof(int));
    c->mc_best_cb = (int*)calloc(256, sizeof(int));
    c->mc_charset = (uint8_t*)calloc(1, 4096);
    c->mc_colram = (uint8_t*)calloc(1, 4096);
    c->next_pts = 0;
}