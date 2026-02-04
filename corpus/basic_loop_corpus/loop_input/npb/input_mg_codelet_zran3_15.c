#include <stdio.h>
#include <stdlib.h>

double ***z;
int m1;
int i;
int j1[10][2];
int j2[10][2];
int j3[10][2];

void init_vars() {
    m1 = 0;

    for (int idx = 0; idx < 10; idx++) {
        j1[idx][1] = 0;
        j2[idx][1] = 0;
        j3[idx][1] = 0;
    }

    z = (double ***)calloc(1, sizeof(double **));
    z[0] = (double **)calloc(1, sizeof(double *));
    z[0][0] = (double *)calloc(1, sizeof(double));
}