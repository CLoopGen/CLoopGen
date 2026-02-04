#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

VEC *u;
MAT *B;
int i;

void init_vars() {
    // Allocate B and u
    B = (MAT*)calloc(1, sizeof(MAT));
    u = (VEC*)calloc(1, sizeof(VEC));

    // Set dimensions: choose m such that total memory is ~64MB for reasonable timing (~0.01s)
    // We're writing B->m diagonal elements, each double is 8 bytes.
    // To get reasonable runtime without being too heavy, pick B->m around 8000-16000.
    B->m = 12000;
    B->n = B->m;
    B->max_m = B->m;
    B->max_n = B->n;
    B->max_size = B->m * B->n;

    u->dim = B->m;
    u->max_dim = u->dim;

    // Allocate base matrix data as a contiguous block
    B->base = (double*)calloc(B->max_size, sizeof(double));
    // Allocate row pointers
    B->me = (double**)calloc(B->max_m, sizeof(double*));
    for (u_int i = 0; i < B->m; i++) {
        B->me[i] = &(B->base[i * B->n]);
    }

    // Allocate vector data
    u->ve = (double*)calloc(u->max_dim, sizeof(double));
    for (u_int i = 0; i < u->dim; i++) {
        u->ve[i] = (double)(i + 1); // arbitrary initialization
    }
}