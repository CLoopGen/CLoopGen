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
int m;
int n;
double sum;

void init_vars() {
    m = 4096;
    n = 4096;
    sum = 0.0;

    A = (ZMAT *)malloc(sizeof(ZMAT));
    A->m = m;
    A->n = n;
    A->max_m = m;
    A->max_n = n;
    A->max_size = m * n;

    A->base = (complex *)malloc(m * n * sizeof(complex));
    A->me = (complex **)malloc(m * sizeof(complex *));

    for (int idx = 0; idx < m; idx++) {
        A->me[idx] = &(A->base[idx * n]);
    }

    for (int idx = 0; idx < m * n; idx++) {
        A->base[idx].re = 1.0;
        A->base[idx].im = 1.0;
    }
}