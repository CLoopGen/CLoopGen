#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define TOTAL_ELEMS (1 << 20)
#define NNZ ((TOTAL_ELEMS / 100) > 100000 ? (TOTAL_ELEMS / 100) : 100000)

size_t j = 5;
double alpha = 1.5;

int *w;
double *x;
int mark = 1;

size_t nz = 0;

int p;

int *Ai;
int *Ap;
double *Ad;
int *Ci;

void init_vars() {
    const size_t num_cols = 1000;
    const size_t num_rows = NNZ / 10 > num_cols ? num_cols : NNZ / 10;
    const size_t nnz_per_col = NNZ / num_cols + 1;

    Ap = (int*)calloc(num_cols + 1, sizeof(int));
    Ai = (int*)malloc(NNZ * sizeof(int));
    Ad = (double*)malloc(NNZ * sizeof(double));
    Ci = (int*)malloc(NNZ * sizeof(int));
    w = (int*)malloc(num_rows * sizeof(int));
    x = (double*)malloc(num_rows * sizeof(double));

    for (size_t col = 0; col < num_cols + 1; ++col) {
        Ap[col] = (col < num_cols) ? col * nnz_per_col : NNZ;
    }

    for (size_t i = 0; i < NNZ; ++i) {
        Ai[i] = rand() % num_rows;
        Ad[i] = (double)(rand()) / RAND_MAX;
    }

    for (size_t i = 0; i < num_rows; ++i) {
        w[i] = 0;
        x[i] = 0.0;
    }

    j = rand() % (num_cols - 1);
    mark = 1;
    nz = 0;
}