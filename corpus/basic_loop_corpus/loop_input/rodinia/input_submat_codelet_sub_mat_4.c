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

MAT *old;
MAT *new;
u_int row1;
u_int col1;
u_int i;

void init_vars() {
    const u_int total_rows = 8000;
    const u_int total_cols = 4000;
    const u_int new_m = 4000;

    old = (MAT*)calloc(1, sizeof(MAT));
    new = (MAT*)calloc(1, sizeof(MAT));

    old->m = total_rows;
    old->n = total_cols;
    old->max_m = total_rows;
    old->max_n = total_cols;
    old->max_size = total_rows * total_cols;
    old->base = (double*)calloc(total_rows * total_cols, sizeof(double));
    old->me = (double**)calloc(total_rows, sizeof(double*));
    for (u_int r = 0; r < total_rows; r++) {
        old->me[r] = old->base + r * total_cols;
    }

    row1 = 1000;
    col1 = 500;

    new->m = new_m;
    new->n = total_cols - col1;
    new->max_m = new_m;
    new->max_n = new->n;
    new->max_size = new_m * new->n;
    new->base = (double*)calloc(new_m * new->n, sizeof(double));
    new->me = (double**)calloc(new_m, sizeof(double*));
    for (u_int r = 0; r < new_m; r++) {
        new->me[r] = new->base + r * new->n;
    }
}