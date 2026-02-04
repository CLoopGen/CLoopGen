#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

double *xc0;
double *yc0;
int Nc;
int R;
int Np;
int i;
int j;
double **xc;
double **yc;
double ***r;

void init_vars() {
    Nc = 8192;
    Np = 32;
    R = 100;

    xc0 = (double*)calloc(Nc, sizeof(double));
    yc0 = (double*)calloc(Nc, sizeof(double));

    xc = (double**)calloc(Nc, sizeof(double*));
    yc = (double**)calloc(Nc, sizeof(double*));
    r = (double***)calloc(Nc, sizeof(double**));

    for (int idx = 0; idx < Nc; idx++) {
        xc[idx] = (double*)calloc(1, sizeof(double));
        yc[idx] = (double*)calloc(1, sizeof(double));
        r[idx] = (double**)calloc(Np, sizeof(double*));
        for (int jdx = 0; jdx < Np; jdx++) {
            r[idx][jdx] = (double*)calloc(1, sizeof(double));
        }
    }

    for (int idx = 0; idx < Nc; idx++) {
        xc0[idx] = (double)(idx * 2);
        yc0[idx] = (double)(idx * 3);
    }
}