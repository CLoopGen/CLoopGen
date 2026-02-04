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
    // Variant 1: Increased computational intensity by unrolling the loop and increasing arithmetic operations
    // Trip count remains the same but each iteration performs more work (unrolled by factor of 2)
    int rnk = x->rnk;
    for (i = rnk - 1; i > 1; i -= 2) {
        // Unroll two iterations: current i and i-1
        bench_iodim *dim_i = &x->dims[i];
        bench_iodim *dim_im1 = &x->dims[i - 1];
        bench_iodim *dim_im2 = &x->dims[i - 2];

        // Original computation for index i-1
        dim_im1->is = dim_i->is * dim_i->n;
        dim_im1->os = dim_i->os * dim_i->n;

        // Additional unrolled computation for index i-2 (if valid)
        if (i - 2 >= 0) {
            dim_im2->is = dim_im1->is * dim_im1->n;
            dim_im2->os = dim_im1->os * dim_im1->n;
        }
    }
    // Handle remaining elements with original logic
    for (; i > 0; --i) {
        x->dims[i - 1].is = x->dims[i].is * x->dims[i].n;
        x->dims[i - 1].os = x->dims[i].os * x->dims[i].n;
    }
}
