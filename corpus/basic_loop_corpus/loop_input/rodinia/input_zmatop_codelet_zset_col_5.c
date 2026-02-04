#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

ZMAT *mat;
ZVEC *vec;
int col;
u_int i;
u_int lim;

void init_vars() {
    lim = 10000000; // ~160 MB of data (10M * 16 bytes per complex)
    
    col = 0;
    i = 0;

    // Allocate vector
    vec = (ZVEC*)malloc(sizeof(ZVEC));
    vec->dim = lim;
    vec->max_dim = lim;
    vec->ve = (complex*)calloc(lim, sizeof(complex));

    // Initialize vector elements
    for (u_int idx = 0; idx < lim; idx++) {
        vec->ve[idx].re = 1.0 + idx * 0.0001;
        vec->ve[idx].im = 0.5 - idx * 0.00005;
    }

    // Allocate matrix structure
    mat = (ZMAT*)malloc(sizeof(ZMAT));
    mat->m = lim;
    mat->n = 1;
    mat->max_m = lim;
    mat->max_n = 1;
    mat->max_size = lim * 1;
    mat->base = (complex*)calloc(lim, sizeof(complex));
    mat->me = (complex**)calloc(lim, sizeof(complex*));

    // Set up row pointers for column access
    for (u_int idx = 0; idx < lim; idx++) {
        mat->me[idx] = &mat->base[idx];
    }

    // Ensure col is within bounds
    if (col >= 1) col = 0;
}