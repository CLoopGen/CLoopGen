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

extern PixContext *pctx;
extern int i;
extern int pix;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2, unrolled to handle remaining elements
    int stride = 2;
    int limit = pctx->cache_size - 1;
    
    for (i = 0; i < limit; i += stride) {
        if (pctx->cache[i] == pix)
            break;
    }
    
    // Handle potential odd index if loop ended prematurely due to stride
    if (i >= limit && (limit % 2) == 1) {
        i = limit - 1;
        if (pctx->cache[i] == pix)
            return;
    }
}
