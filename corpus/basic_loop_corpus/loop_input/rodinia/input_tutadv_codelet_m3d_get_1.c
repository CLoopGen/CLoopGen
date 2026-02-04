#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

int l = 1000;
int m = 500;
MAT3D *mat;
int i;

void init_vars() {
    mat = (MAT3D*)calloc(1, sizeof(MAT3D));
    mat->l = l;
    mat->m = m;
    mat->n = 1;
    mat->max_l = l;
    mat->max_m = m;
    mat->max_n = 1;

    mat->base = (double*)calloc(l * m * 1, sizeof(double));
    mat->me2d = (double**)calloc(l * m, sizeof(double*));
    for (int idx = 0; idx < l * m; idx++) {
        mat->me2d[idx] = &mat->base[idx];
    }

    mat->me = (double***)calloc(l, sizeof(double**));
}