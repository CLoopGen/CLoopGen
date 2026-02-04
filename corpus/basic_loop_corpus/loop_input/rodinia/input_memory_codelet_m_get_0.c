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

int m = 1000;
int n = 1000;
MAT *matrix;
int i;

void init_vars() {
    matrix = (MAT*)malloc(sizeof(MAT));
    matrix->m = m;
    matrix->n = n;
    matrix->max_m = m;
    matrix->max_n = n;
    matrix->max_size = m * n;
    
    matrix->base = (double*)calloc(m * n, sizeof(double));
    matrix->me = (double**)malloc(m * sizeof(double*));
}