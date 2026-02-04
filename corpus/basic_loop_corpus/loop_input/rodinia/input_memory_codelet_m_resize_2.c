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

static double **me_data;
static double *base_data;
MAT *A;
int new_m;
int new_n;
int i;

void init_vars() {
    new_m = 4096;
    new_n = 512;
    
    base_data = (double*)calloc(new_m * new_n, sizeof(double));
    me_data = (double**)malloc(new_m * sizeof(double*));
    
    A = (MAT*)malloc(sizeof(MAT));
    A->m = new_m;
    A->n = new_n;
    A->max_m = new_m;
    A->max_n = new_n;
    A->max_size = new_m * new_n;
    A->me = me_data;
    A->base = base_data;
}