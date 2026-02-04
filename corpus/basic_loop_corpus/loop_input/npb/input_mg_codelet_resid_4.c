#include <stdlib.h>
#include <math.h>

double ***u;
double ***v;
double ***r;
int n1 = 128;
int n2 = 128;
int n3 = 128;
double a[4] = {0.1, 0.2, 0.3, 0.4};
int i3;
int i2;
int i1;
double u1[1037];
double u2[1037];

void init_vars() {
    int i, j, k;

    u = (double***)malloc(n3 * sizeof(double**));
    v = (double***)malloc(n3 * sizeof(double**));
    r = (double***)malloc(n3 * sizeof(double**));

    for (i = 0; i < n3; i++) {
        u[i] = (double**)malloc(n2 * sizeof(double*));
        v[i] = (double**)malloc(n2 * sizeof(double*));
        r[i] = (double**)malloc(n2 * sizeof(double*));
        for (j = 0; j < n2; j++) {
            u[i][j] = (double*)malloc(n1 * sizeof(double));
            v[i][j] = (double*)malloc(n1 * sizeof(double));
            r[i][j] = (double*)malloc(n1 * sizeof(double));
            for (k = 0; k < n1; k++) {
                u[i][j][k] = ((double)rand()) / RAND_MAX;
                v[i][j][k] = ((double)rand()) / RAND_MAX;
                r[i][j][k] = 0.0;
            }
        }
    }

    for (i = 0; i < 1037; i++) {
        u1[i] = 0.0;
        u2[i] = 0.0;
    }
}