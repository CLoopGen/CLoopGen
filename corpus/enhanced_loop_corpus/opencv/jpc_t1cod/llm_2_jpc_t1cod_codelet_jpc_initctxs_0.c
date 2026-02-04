#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int mps;
    int_fast16_t ind;
} jpc_mqctx_t;

extern jpc_mqctx_t *ctx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled initialization pattern
    // Instead of using switch-case, precompute ind values in a static array for consecutive access
    static const int_fast16_t ind_values[] = {3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46};
    int size = sizeof(ind_values) / sizeof(ind_values[0]);
    for (i = 0; i < size; ++i) {
        ctx->mps = 0;
        ctx->ind = ind_values[i];
        ++ctx;
    }
}
