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

A64Context *c;
int a;
int b;
uint8_t index1[256];
uint8_t index2[256];
uint8_t dither[256];
int i;
int distance;

static int internal_mc_meta_charset[1024];
static int internal_mc_charmap[1024];
static int internal_mc_best_cb[1024];
static uint8_t internal_mc_charset[1024];
static uint8_t internal_mc_colram[1024];
static uint8_t internal_mc_palette[1024];

void init_vars() {
    c = (A64Context*)malloc(sizeof(A64Context));
    if (!c) return;

    c->mc_lifetime = 100;
    c->mc_use_5col = 1;
    c->mc_frame_counter = 0;
    c->mc_meta_charset = internal_mc_meta_charset;
    c->mc_charmap = internal_mc_charmap;
    c->mc_best_cb = internal_mc_best_cb;
    c->mc_charset = internal_mc_charset;
    c->mc_colram = internal_mc_colram;
    c->mc_palette = internal_mc_palette;
    c->mc_pal_size = 5;
    c->next_pts = 0;

    for (int j = 0; j < 64; j++) {
        c->randctx.state[j] = j * 31;
    }
    c->randctx.index = 0;

    c->mc_luma_vals[0] = 0;
    c->mc_luma_vals[1] = 64;
    c->mc_luma_vals[2] = 128;
    c->mc_luma_vals[3] = 192;
    c->mc_luma_vals[4] = 255;

    a = 0;
    b = 0;
    i = 0;
    distance = 0;

    for (int j = 0; j < 256; j++) {
        index1[j] = 0;
        index2[j] = 0;
        dither[j] = 0;
    }

    for (int j = 0; j < 1024; j++) {
        internal_mc_meta_charset[j] = rand() % 100;
        internal_mc_charmap[j] = rand() % 256;
        internal_mc_best_cb[j] = rand() % 50;
        internal_mc_charset[j] = rand() % 256;
        internal_mc_colram[j] = rand() % 16;
        internal_mc_palette[j] = rand() % 256;
    }
}