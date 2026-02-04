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
    // Variant 2: Indirect memory access using an index mapping array (simulated via modulo-based virtual indices)
    int indices[12];
    int n = pctx->cache_size - 1;
    
    // Precompute indirect access pattern: reversed order access
    for (int j = 0; j < n; j++) {
        indices[j] = n - 1 - j;
    }
    
    for (i = 0; i < n; i++) {
        int actual_index = indices[i];  // Indirect access
        if (pctx->cache[actual_index] == pix) {
            i = actual_index;  // Preserve original 'i' semantics as found index
            break;
        }
    }
}
