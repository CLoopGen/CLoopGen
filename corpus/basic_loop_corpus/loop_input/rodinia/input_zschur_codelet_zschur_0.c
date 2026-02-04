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

ZMAT *A;
int i;
int j;
complex **A_me;

void init_vars() {
    A = (ZMAT*)malloc(sizeof(ZMAT));
    A->m = 5000;
    A->n = 5000;
    A->max_m = A->m;
    A->max_n = A->n;
    A->max_size = A->m * A->n;
    A->base = (complex*)calloc(A->max_size, sizeof(complex));
    A->me = (complex**)malloc(A->m * sizeof(complex*));
    for (u_int idx = 0; idx < A->m; idx++) {
        A->me[idx] = A->base + idx * A->n;
    }
    A_me = A->me;
}