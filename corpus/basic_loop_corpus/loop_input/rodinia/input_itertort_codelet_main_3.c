#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

int kk = 1000;
int j;

MAT *H1;

void init_vars() {
    H1 = (MAT*)calloc(1, sizeof(MAT));
    H1->max_m = kk;
    H1->max_n = kk;
    H1->m = kk;
    H1->n = kk;
    H1->max_size = kk * kk;

    H1->base = (double*)calloc(kk * kk, sizeof(double));
    H1->me = (double**)calloc(kk, sizeof(double*));

    for (int i = 0; i < kk; i++) {
        H1->me[i] = H1->base + i * kk;
        for (int j = 0; j < kk; j++) {
            H1->me[i][j] = (double)(i * kk + j) / 100.0;
        }
    }
}