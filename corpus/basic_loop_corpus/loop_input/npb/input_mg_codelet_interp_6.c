#include <stdio.h>
#include <stdlib.h>

double ***z;
int mm1 = 64;
int mm2 = 64;
int mm3 = 64;
double ***u;
int i3;
int i2;
int i1;
double z1[1037];
double z2[1037];
double z3[1037];

void init_vars() {
    int i, j, k;

    z = (double***)calloc(mm3, sizeof(double**));
    for (i = 0; i < mm3; i++) {
        z[i] = (double**)calloc(mm2, sizeof(double*));
        for (j = 0; j < mm2; j++) {
            z[i][j] = (double*)calloc(mm1, sizeof(double));
            for (k = 0; k < mm1; k++) {
                z[i][j][k] = (double)(i + j + k) / 1.7;
            }
        }
    }

    u = (double***)calloc(2 * mm3, sizeof(double**));
    for (i = 0; i < 2 * mm3; i++) {
        u[i] = (double**)calloc(2 * mm2, sizeof(double*));
        for (j = 0; j < 2 * mm2; j++) {
            u[i][j] = (double*)calloc(2 * mm1, sizeof(double));
            for (k = 0; k < 2 * mm1; k++) {
                u[i][j][k] = (double)(i + j + k) / 3.7;
            }
        }
    }

    for (i = 0; i < 1037; i++) {
        z1[i] = 0.0;
        z2[i] = 0.0;
        z3[i] = 0.0;
    }
}