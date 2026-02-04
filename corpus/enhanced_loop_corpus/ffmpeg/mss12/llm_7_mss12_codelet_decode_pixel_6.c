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
    int local_val = val;
    int updated_idx = idx;
    int cache_size_local = pctx->cache_size;
    for (i = 0; i < cache_size_local; i++) {
        uint8_t current_cache = pctx->cache[i];
        int match = 0;
        for (j = 0; j < num_ngb; j++) {
            if (current_cache == ngb[j]) {
                match = 1;
                break;
            }
        }
        if (!match && updated_idx != local_val) {
            updated_idx++;
        } else if (!match && updated_idx == local_val) {
            break;
        }
    }
    idx = updated_idx;
}
