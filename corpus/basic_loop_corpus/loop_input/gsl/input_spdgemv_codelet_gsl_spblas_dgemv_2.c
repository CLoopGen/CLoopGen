#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha = 1.5;
size_t j;
size_t incX = 1;
size_t incY = 1;
size_t lenX;

double *X;
double *Y;
double *Ad;
int *Ap;
int *Ai;
int p;

void init_vars() {
    lenX = 1 << 20; // 1 million elements

    // CSR matrix structure: average ~10 nonzeros per row
    size_t nnz = lenX * 10;

    X = (double*)aligned_alloc(32, lenX * incX * sizeof(double));
    Y = (double*)aligned_alloc(32, (nnz) * incY * sizeof(double));
    Ad = (double*)aligned_alloc(32, nnz * sizeof(double));
    Ai = (int*)aligned_alloc(32, nnz * sizeof(int));
    Ap = (int*)aligned_alloc(32, (lenX + 1) * sizeof(int));

    Ap[0] = 0;
    for (size_t i = 0; i < lenX; ++i) {
        Ap[i + 1] = Ap[i] + (rand() % 20 + 1); // 1 to 20 nonzeros per row
        X[i * incX] = 1.0 / (i + 1);
        for (int p = Ap[i]; p < Ap[i + 1]; ++p) {
            Ai[p] = rand() % (lenX * 2); // arbitrary column index
            Ad[p] = 0.1;
        }
    }

    for (size_t i = 0; i < nnz; ++i) {
        Y[Ai[i] * incY] = 0.0;
    }

    alpha = 1.5;
}