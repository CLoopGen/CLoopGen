#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef struct {
    int l;
    int m;
    int n;
    int max_l;
    int max_m;
    int max_n;
    double ***me;
    double *base;
    double **me2d;
} MAT3D;

int l = 100;
int m = 100;
int n = 100;
MAT3D *mat;
int i;
int j;
int k;

void init_vars() {
    mat = (MAT3D*)calloc(1, sizeof(MAT3D));
    mat->l = l;
    mat->m = m;
    mat->n = n;
    mat->max_l = l;
    mat->max_m = m;
    mat->max_n = n;

    size_t total_size = (size_t)l * m * n;
    mat->base = (double*)calloc(total_size, sizeof(double));
    
    mat->me2d = (double**)calloc(l * m, sizeof(double*));
}