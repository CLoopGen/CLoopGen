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
    double *adata = a->data;
    double *bdata = b->data;
    size_t sa = stride_a;
    size_t sb = stride_b;
    for (i = 0; i < N; i++) {
        double br = bdata[i * sb];
        double temp_real = adata[2 * i * sa];
        double temp_imag = adata[2 * i * sa + 1];
        adata[2 * i * sa] = temp_real * br;
        adata[2 * i * sa + 1] = temp_imag * br;
    }
}
