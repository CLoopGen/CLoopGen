#include <stdlib.h>
#include <math.h>

double ***z;
int mm1 = 128;
int mm2 = 128;
int mm3 = 128;
double ***u;
int i3;
int i2;
int i1;
int d1 = 1;
int d2 = 1;
int t1 = 1;
int t2 = 1;
int t3 = 1;

void init_vars() {
    int i, j, k;

    z = (double***)calloc(mm3, sizeof(double**));
    for (i = 0; i < mm3; i++) {
        z[i] = (double**)calloc(mm2, sizeof(double*));
        for (j = 0; j < mm2; j++) {
            z[i][j] = (double*)calloc(mm1, sizeof(double));
            for (k = 0; k < mm1; k++) {
                z[i][j][k] = (double)(i + j + k) / 100.0;
            }
        }
    }

    u = (double***)calloc(2 * mm3, sizeof(double**));
    for (i = 0; i < 2 * mm3; i++) {
        u[i] = (double**)calloc(2 * mm2, sizeof(double*));
        for (j = 0; j < 2 * mm2; j++) {
            u[i][j] = (double*)calloc(2 * mm1, sizeof(double));
            for (k = 0; k < 2 * mm1; k++) {
                u[i][j][k] = (double)(i + j + k) / 200.0;
            }
        }
    }
}