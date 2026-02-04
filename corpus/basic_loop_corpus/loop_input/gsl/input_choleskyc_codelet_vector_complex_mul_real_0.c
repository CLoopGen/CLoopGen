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

static gsl_block_complex *block_a = NULL;
static gsl_block *block_b = NULL;
static double *data_a = NULL;
static double *data_b = NULL;

gsl_vector_complex *a;
gsl_vector *b;
size_t N = 0;
size_t stride_a = 1;
size_t stride_b = 1;
size_t i = 0;

void init_vars() {
    N = 67108864;  // ~512MB of data: N doubles in b, 2*N doubles in a -> total ~512MB
    
    block_a = (gsl_block_complex*)calloc(1, sizeof(gsl_block_complex));
    block_b = (gsl_block*)calloc(1, sizeof(gsl_block));
    
    data_a = (double*)calloc(2 * N, sizeof(double));
    data_b = (double*)calloc(N, sizeof(double));
    
    if (!block_a || !block_b || !data_a || !data_b) {
        exit(1);
    }
    
    for (size_t j = 0; j < N; j++) {
        data_b[j] = 1.0 + 0.01 * (j % 100);
    }
    
    for (size_t j = 0; j < 2 * N; j++) {
        data_a[j] = 0.5;
    }
    
    block_a->size = 2 * N;
    block_a->data = data_a;
    
    block_b->size = N;
    block_b->data = data_b;
    
    a = (gsl_vector_complex*)calloc(1, sizeof(gsl_vector_complex));
    b = (gsl_vector*)calloc(1, sizeof(gsl_vector));
    
    if (!a || !b) {
        exit(1);
    }
    
    a->size = N;
    a->stride = stride_a;
    a->data = data_a;
    a->block = block_a;
    a->owner = 1;
    
    b->size = N;
    b->stride = stride_b;
    b->data = data_b;
    b->block = block_b;
    b->owner = 1;
}