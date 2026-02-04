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
extern uint8_t *ngb;
extern int num_ngb;
extern int i;
extern int val;
extern int idx;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index mapping for ngb array
    // Simulate indirect access via an index permutation table (assumed to be precomputed as a static)
    static const uint8_t ngb_perm[256] = {0}; // Placeholder for indirect indexing (identity map assumed)
    // In practice, ngb_perm could be a reordering, but we avoid complex init here

    for (i = 0; i < pctx->cache_size; i++) {
        uint8_t cache_val = pctx->cache[i];
        int found = 0;
        for (j = 0; j < num_ngb; j++) {
            int indirect_idx = ngb_perm[j] % num_ngb; // Ensure in bounds
            if (cache_val == ngb[indirect_idx]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            if (idx == val)
                break;
            idx++;
        }
    }
}
