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
    if (pctx->cache_size <= 0 || num_ngb <= 0) return;
    for (i = 0; i < pctx->cache_size; i++) {
        j = 0;
        for (; j < num_ngb; j++) {
            if (pctx->cache[i] == ngb[j]) {
                goto next_iteration;
            }
        }
        if (idx == val) break;
        idx++;
        next_iteration: ;
    }
}
