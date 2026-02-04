#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Model {
    int16_t cum_prob[257];
    int16_t weights[257];
    uint8_t idx2sym[257];
    int num_syms;
    int thr_weight;
    int threshold;
} Model;

typedef struct PixContext {
    int cache_size;
    int num_syms;
    uint8_t cache[12];
    Model cache_model;
    Model full_model;
    Model sec_models[15][4];
    int special_initial_cache;
} PixContext;

PixContext *pctx;
int i;
int pix;

void init_vars() {
    pctx = (PixContext*)calloc(1, sizeof(PixContext));
    if (!pctx) exit(1);

    pctx->cache_size = 12;
    pctx->num_syms = 256;
    for (int j = 0; j < 12; j++) {
        pctx->cache[j] = (uint8_t)(j * 21); 
    }
    pctx->special_initial_cache = 0;

    for (int j = 0; j < 257; j++) {
        pctx->cache_model.cum_prob[j] = (int16_t)j;
        pctx->cache_model.weights[j] = (int16_t)(j % 100);
        pctx->cache_model.idx2sym[j] = (uint8_t)j;
    }
    pctx->cache_model.num_syms = 256;
    pctx->cache_model.thr_weight = 50;
    pctx->cache_model.threshold = 100;

    for (int j = 0; j < 257; j++) {
        pctx->full_model.cum_prob[j] = (int16_t)j;
        pctx->full_model.weights[j] = (int16_t)(j % 150);
        pctx->full_model.idx2sym[j] = (uint8_t)((j + 10) % 256);
    }
    pctx->full_model.num_syms = 256;
    pctx->full_model.thr_weight = 75;
    pctx->full_model.threshold = 120;

    for (int k = 0; k < 15; k++) {
        for (int m = 0; m < 4; m++) {
            Model* model = &pctx->sec_models[k][m];
            for (int j = 0; j < 257; j++) {
                model->cum_prob[j] = (int16_t)((j + k * m) % 257);
                model->weights[j] = (int16_t)((j * 2 + m) % 200);
                model->idx2sym[j] = (uint8_t)((j + k) % 256);
            }
            model->num_syms = 256;
            model->thr_weight = 40 + k % 20;
            model->threshold = 90 + m * 10;
        }
    }

    pix = 42;
    i = 0;
}