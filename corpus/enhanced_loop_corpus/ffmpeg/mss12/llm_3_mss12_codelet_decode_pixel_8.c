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
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access using an index map (simulated via offset array to demonstrate indirection)
    int indices[12];
    for (int j = 0; j < 12; j++) {
        indices[j] = j;
    }
    // Only process valid range [1, val]
    for (i = val; i > 0; i--) {
        int src_idx = indices[i - 1];
        int dst_idx = indices[i];
        pctx->cache[dst_idx] = pctx->cache[src_idx];
    }
}
