#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_block_complex_struct {
    size_t size;
    double *data;
};


typedef struct gsl_block_complex_struct gsl_block_complex;

typedef struct {
    size_t size;
    size_t stride;
    double *data;
    gsl_block_complex *block;
    int owner;
} gsl_vector_complex;

struct gsl_block_struct {
    size_t size;
    double *data;
};


typedef struct gsl_block_struct gsl_block;

typedef struct {
    size_t size;
    size_t stride;
    double *data;
    gsl_block *block;
    int owner;
} gsl_vector;

extern gsl_vector_complex *a;
extern  gsl_vector *b;
extern  size_t N;
extern  size_t stride_a;
extern  size_t stride_b;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Reverse Iteration and Data Prefetching
    double *adata = a->data;
    double *bdata = b->data;
    size_t sa = 2 * stride_a;
    size_t sb = stride_b;

    // Reverse iteration to alter memory access pattern and improve cache behavior in some contexts
    for (i = N; i > 0; ) {
        i--;
        double br = bdata[i * sb];
        
        // Prefetch next iteration data (if supported by hardware, otherwise harmless)
        if (i > 0) {
            __builtin_prefetch(&bdata[(i-1) * sb], 0, 0);
            __builtin_prefetch(&adata[2*(i-1)*sa], 0, 0);
        }

        adata[2 * i * sa / 2] *= br;           // Equivalent to 2*i*stride_a
        adata[2 * i * sa / 2 + 1] *= br;       // Ensures strided write pattern remains correct
    }
}
