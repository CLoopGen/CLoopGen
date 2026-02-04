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
uint8_t *ngb;
int num_ngb;
int i;
int val;
int idx;
int j;

void init_vars() {
    // Allocate and initialize pctx
    pctx = (PixContext*)calloc(1, sizeof(PixContext));
    pctx->cache_size = 12;  // Must be <= 12 to fit cache array
    pctx->num_syms = 256;

    // Initialize cache with dummy data
    for (int c = 0; c < pctx->cache_size; c++) {
        pctx->cache[c] = (uint8_t)(c * 11 + 7);  // Arbitrary non-repeating pattern
    }

    // Initialize model fields in cache_model and full_model
    for (int k = 0; k < 257; k++) {
        pctx->cache_model.cum_prob[k] = (int16_t)k;
        pctx->cache_model.weights[k] = (int16_t)(k % 32);
        pctx->cache_model.idx2sym[k] = (uint8_t)k;
        pctx->full_model.cum_prob[k] = (int16_t)k;
        pctx->full_model.weights[k] = (int16_t)(k % 32);
        pctx->full_model.idx2sym[k] = (uint8_t)k;
    }
    pctx->cache_model.num_syms = 256;
    pctx->cache_model.thr_weight = 100;
    pctx->cache_model.threshold = 128;
    pctx->full_model.num_syms = 256;
    pctx->full_model.thr_weight = 100;
    pctx->full_model.threshold = 128;

    // Initialize sec_models
    for (int a = 0; a < 15; a++) {
        for (int b = 0; b < 4; b++) {
            Model* m = &pctx->sec_models[a][b];
            for (int k = 0; k < 257; k++) {
                m->cum_prob[k] = (int16_t)((a + b + k) % 32768);
                m->weights[k] = (int16_t)((a * b + k) % 32768);
                m->idx2sym[k] = (uint8_t)(k % 256);
            }
            m->num_syms = 256;
            m->thr_weight = 90 + a;
            m->threshold = 120 + b;
        }
    }
    pctx->special_initial_cache = 42;

    // Allocate ngb array: aim for ~100MB of data to ensure loop takes ~0.01s
    // Inner loop does pctx->cache_size (12) * num_ngb comparisons per outer iteration.
    // To get measurable time, set num_ngb large enough.
    num_ngb = 1 << 20;  // 1 million elements (~1MB), sufficient for timing
    ngb = (uint8_t*)malloc(num_ngb * sizeof(uint8_t));
    if (!ngb) exit(1);

    // Fill ngb with pseudo-random but deterministic data
    for (int n = 0; n < num_ngb; n++) {
        ngb[n] = (uint8_t)((n * 17 + 251) % 256);
    }

    // Initialize loop control variables
    i = 0;
    j = 0;
    val = 5;   // Ensure this is within reasonable range
    idx = 0;   // Will be incremented until it hits val
}