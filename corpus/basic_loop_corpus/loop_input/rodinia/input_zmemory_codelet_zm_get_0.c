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

int m = 8192;
int n = 4096;
u_int i;
ZMAT *matrix;

void init_vars() {
    matrix = (ZMAT *)malloc(sizeof(ZMAT));
    matrix->m = m;
    matrix->n = n;
    matrix->max_m = m;
    matrix->max_n = n;
    matrix->max_size = m * n;
    
    matrix->base = (complex *)calloc(m * n, sizeof(complex));
    matrix->me = (complex **)malloc(m * sizeof(complex *));
}