#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

PERM *pivot;
VEC *x;
int i;
int j;
int l;
int n = 2000;
int n1 = 1000;
int pi;
int lb = 1500;
int jmin;
int maxj;
double c;
double **bA_v;

void init_vars() {
    // Allocate and initialize x vector
    x = (VEC *)malloc(sizeof(VEC));
    x->dim = n;
    x->max_dim = n;
    x->ve = (double *)calloc(n, sizeof(double));
    for (int idx = 0; idx < n; idx++) {
        x->ve[idx] = 1.0 + idx * 0.01;
    }

    // Allocate and initialize pivot permutation structure
    pivot = (PERM *)malloc(sizeof(PERM));
    pivot->size = lb;
    pivot->max_size = lb;
    pivot->pe = (u_int *)malloc(lb * sizeof(u_int));
    for (int idx = 0; idx < lb; idx++) {
        pivot->pe[idx] = idx;
    }
    // Create some indirect references to simulate path compression
    for (int idx = 1; idx < lb; idx++) {
        if (pivot->pe[idx] == idx && idx % 3 == 0) {
            pivot->pe[idx] = pivot->pe[idx-1];
        }
    }

    // Allocate and initialize bA_v matrix (lb x n)
    bA_v = (double **)malloc(lb * sizeof(double *));
    for (int idx = 0; idx < lb; idx++) {
        bA_v[idx] = (double *)malloc(n * sizeof(double));
        for (int jdx = 0; jdx < n; jdx++) {
            bA_v[idx][jdx] = 0.001 * (idx + 1) / (jdx + 1);
        }
    }

    // Initialize remaining scalar variables used in loop bounds
    i = 0;
    j = 0;
    l = 0;
    pi = 0;
    jmin = 0;
    maxj = 0;
    c = 0.0;
}