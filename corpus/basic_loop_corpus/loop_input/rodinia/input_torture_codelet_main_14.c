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

static MAT D_storage;
static double *matrix_data;
static double **row_pointers;
static u_int size = 2048;  // ~16MB for double matrix, ensures ~0.01s runtime

MAT *D = &D_storage;
int i;

void init_vars() {
    D->m = size;
    D->n = size;
    D->max_m = size;
    D->max_n = size;
    D->max_size = size * size;
    
    matrix_data = (double*)calloc(size * size, sizeof(double));
    row_pointers = (double**)malloc(size * sizeof(double*));
    
    for (u_int idx = 0; idx < size; idx++) {
        row_pointers[idx] = &matrix_data[idx * size];
        for (u_int j = 0; j < size; j++) {
            row_pointers[idx][j] = (double)(idx * size + j);
        }
    }
    
    D->me = row_pointers;
    D->base = matrix_data;
}