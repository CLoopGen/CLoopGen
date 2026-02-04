#include <stdio.h>
#include <stdlib.h>

double ***u;
int n1 = 256;
int n2 = 256;
int n3 = 256;
int i1;
int i2;

void init_vars() {
    u = (double ***)calloc(n3, sizeof(double **));
    for (int i = 0; i < n3; i++) {
        u[i] = (double **)calloc(n2, sizeof(double *));
        for (int j = 0; j < n2; j++) {
            u[i][j] = (double *)calloc(n1, sizeof(double));
            for (int k = 0; k < n1; k++) {
                u[i][j][k] = (double)(i * n2 * n1 + j * n1 + k);
            }
        }
    }
}