#include <stdlib.h>

double ***z;
int n1 = 64;
int n2 = 64;
int n3 = 64;
int i1, i2, i3;

void init_vars() {
    z = (double***)malloc(n3 * sizeof(double**));
    for (int i = 0; i < n3; i++) {
        z[i] = (double**)malloc(n2 * sizeof(double*));
        for (int j = 0; j < n2; j++) {
            z[i][j] = (double*)calloc(n1, sizeof(double));
        }
    }
}