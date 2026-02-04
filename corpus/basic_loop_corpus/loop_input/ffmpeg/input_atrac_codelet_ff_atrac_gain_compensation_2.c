#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AtracGCContext {
    float gain_tab1[16];
    float gain_tab2[31];
    int id2exp_offset;
    int loc_scale;
    int loc_size;
} AtracGCContext;

typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

AtracGCContext *gctx = NULL;
float *in = NULL;
float *prev = NULL;
AtracGainInfo *gc_now = NULL;
float *out = NULL;
float lev;
float gc_scale;
float gain_inc;
int i;
int pos;
int lastpos;

void init_vars() {
    gctx = (AtracGCContext *)malloc(sizeof(AtracGCContext));
    for (int j = 0; j < 16; j++) {
        gctx->gain_tab1[j] = 1.0f + j * 0.1f;
    }
    for (int j = 0; j < 31; j++) {
        gctx->gain_tab2[j] = 1.0f + j * 0.05f;
    }
    gctx->id2exp_offset = 15;
    gctx->loc_scale = 8;
    gctx->loc_size = 16;

    gc_now = (AtracGainInfo *)malloc(sizeof(AtracGainInfo));
    gc_now->num_points = 4;
    int base_loc = 0;
    for (int j = 0; j < 4; j++) {
        gc_now->lev_code[j] = (j * 3) % 16;
        gc_now->loc_code[j] = base_loc;
        base_loc += (j + 1) * 64;
    }

    size_t data_size = 1 << 20;
    in = (float *)calloc(data_size, sizeof(float));
    prev = (float *)calloc(data_size, sizeof(float));
    out = (float *)calloc(data_size, sizeof(float));

    gc_scale = 0.5f;
    pos = 0;

    for (size_t j = 0; j < data_size; j++) {
        in[j] = (float)(rand()) / RAND_MAX;
        prev[j] = (float)(rand()) / RAND_MAX;
    }
}