#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

double alpha = 1.5;
size_t j;
size_t incX = 1;
size_t incY = 1;
size_t lenY;

double *X;
double *Y;
double *Ad;
int *Ap;
int *Ai;
int p;

void init_vars() {
    lenY = 1 << 20;  

    size_t nnz_per_row = 8;
    size_t total_nnz = lenY * nnz_per_row;

    X = (double*)calloc(lenY * incX, sizeof(double));
    Y = (double*)calloc(lenY * incY, sizeof(double));
    Ad = (double*)malloc(total_nnz * sizeof(double));
    Ai = (int*)malloc(total_nnz * sizeof(int));
    Ap = (int*)malloc((lenY + 1) * sizeof(int));

    if (!X || !Y || !Ad || !Ai || !Ap) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    Ap[0] = 0;
    for (size_t i = 0; i < lenY; ++i) {
        int start = Ap[i];
        int end = start + nnz_per_row;
        Ap[i + 1] = end;

        for (int k = start; k < end; ++k) {
            Ai[k] = rand() % lenY;
            Ad[k] = (double)(rand()) / RAND_MAX;
        }
    }

    for (size_t i = 0; i < lenY * incX; ++i) {
        X[i] = (double)(rand()) / RAND_MAX;
    }
    for (size_t i = 0; i < lenY * incY; ++i) {
        Y[i] = (double)(rand()) / RAND_MAX;
    }

    alpha = 1.5;
}