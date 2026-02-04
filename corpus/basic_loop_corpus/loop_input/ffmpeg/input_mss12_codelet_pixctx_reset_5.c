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

PixContext *ctx;
int i;

void init_vars() {
    ctx = (PixContext*)malloc(sizeof(PixContext));
    ctx->cache_size = 12;
    ctx->num_syms = 256;
    ctx->special_initial_cache = 0;

    for (int j = 0; j < 257; j++) {
        ctx->cache_model.cum_prob[j] = (int16_t)j;
        ctx->cache_model.weights[j] = (int16_t)(j % 32);
        ctx->cache_model.idx2sym[j] = (uint8_t)j;
    }
    ctx->cache_model.num_syms = 256;
    ctx->cache_model.thr_weight = 1000;
    ctx->cache_model.threshold = 2000;

    for (int j = 0; j < 257; j++) {
        ctx->full_model.cum_prob[j] = (int16_t)j;
        ctx->full_model.weights[j] = (int16_t)(j % 64);
        ctx->full_model.idx2sym[j] = (uint8_t)((j + 128) % 256);
    }
    ctx->full_model.num_syms = 256;
    ctx->full_model.thr_weight = 2000;
    ctx->full_model.threshold = 4000;

    for (int k = 0; k < 15; k++) {
        for (int l = 0; l < 4; l++) {
            for (int j = 0; j < 257; j++) {
                ctx->sec_models[k][l].cum_prob[j] = (int16_t)j;
                ctx->sec_models[k][l].weights[j] = (int16_t)(j % 16);
                ctx->sec_models[k][l].idx2sym[j] = (uint8_t)((j + k * 4 + l) % 256);
            }
            ctx->sec_models[k][l].num_syms = 256;
            ctx->sec_models[k][l].thr_weight = 500 + k * 100 + l * 25;
            ctx->sec_models[k][l].threshold = 1000 + k * 200 + l * 50;
        }
    }

    for (int j = 0; j < 12; j++) {
        ctx->cache[j] = (uint8_t)0;
    }
}