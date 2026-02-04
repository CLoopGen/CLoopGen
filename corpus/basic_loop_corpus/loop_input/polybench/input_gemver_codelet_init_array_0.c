#include <stdio.h>
#include <inttypes.h>

int n = 1000;
double A[2000][2000];
double u1[2000];
double v1[2000];
double u2[2000];
double v2[2000];
double w[2000];
double x[2000];
double y[2000];
double z[2000];
int i;
int j;
double fn = 1000.0;

void init_vars() {
    for (i = 0; i < n; i++) {
        u1[i] = 0.0;
        v1[i] = 0.0;
        u2[i] = 0.0;
        v2[i] = 0.0;
        w[i] = 0.0;
        x[i] = 0.0;
        y[i] = 0.0;
        z[i] = 0.0;
        for (j = 0; j < n; j++) {
            A[i][j] = 0.0;
        }
    }
}