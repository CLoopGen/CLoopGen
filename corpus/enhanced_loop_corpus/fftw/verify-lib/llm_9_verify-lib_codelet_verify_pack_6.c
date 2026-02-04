#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    int is;
    int os;
} bench_iodim;

typedef struct {
    int rnk;
    bench_iodim *dims;
} bench_tensor;

extern bench_tensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count and modified arithmetic to increase stride, lowering total operations
    // Only process every other dimension, effectively halving the trip count
    // This reduces computational load while maintaining similar structural behavior
    int step = 2;
    int start = (x->rnk - 1) % 2 == 0 ? x->rnk - 2 : x->rnk - 1; // Align start to nearest odd index

    for (i = start; i > 0; i -= step) {
        // Perform computation with an additional additive term to increase arithmetic complexity slightly
        int temp_n = x->dims[i].n;
        x->dims[i - 1].is = x->dims[i].is * temp_n + temp_n; // Extra addition
        x->dims[i - 1].os = x->dims[i].os * temp_n + temp_n;
        
        // Ensure forward progress even when step skips indices
        if (i - 2 >= 0) {
            // Propagate only one level deeper due to larger step
            x->dims[i - 2].is = x->dims[i - 1].is * x->dims[i - 1].n;
            x->dims[i - 2].os = x->dims[i - 1].os * x->dims[i - 1].n;
        }
    }
    // Final cleanup pass for any missed dependencies (minimal)
    if ((x->rnk - 1) > 0 && x->dims[1].is != 0) {
        x->dims[0].is = x->dims[1].is * x->dims[1].n;
        x->dims[0].os = x->dims[1].os * x->dims[1].n;
    }
}
