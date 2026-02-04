#include <stdlib.h>
#include <stdio.h>

double ***r;
double ***s;
int m1j;
int m2j;
int m3j;
int j3;
int j2;
int j1;
int i3;
int i2;
int i1;
int d1;
int d2;
int d3;
double x1[1037];
double y1[1037];
double x2;
double y2;

void init_vars() {
    m1j = 64;
    m2j = 64;
    m3j = 64;
    d1 = 1;
    d2 = 1;
    d3 = 1;

    int r_dim1 = 2 * m3j - d3 + 3;
    int r_dim2 = 2 * m2j - d2 + 3;
    int r_dim3 = 2 * m1j - d1 + 3;

    int s_dim1 = m3j;
    int s_dim2 = m2j;
    int s_dim3 = m1j;

    // Allocate r
    r = (double***)calloc(r_dim1, sizeof(double**));
    for (int i = 0; i < r_dim1; i++) {
        r[i] = (double**)calloc(r_dim2, sizeof(double*));
        for (int j = 0; j < r_dim2; j++) {
            r[i][j] = (double*)calloc(r_dim3, sizeof(double));
            for (int k = 0; k < r_dim3; k++) {
                r[i][j][k] = (double)rand() / RAND_MAX;
            }
        }
    }

    // Allocate s
    s = (double***)calloc(s_dim1, sizeof(double**));
    for (int i = 0; i < s_dim1; i++) {
        s[i] = (double**)calloc(s_dim2, sizeof(double*));
        for (int j = 0; j < s_dim2; j++) {
            s[i][j] = (double*)calloc(s_dim3, sizeof(double));
        }
    }

    // Initialize x1 and y1 arrays
    for (int i = 0; i < 1037; i++) {
        x1[i] = 0.0;
        y1[i] = 0.0;
    }

    x2 = 0.0;
    y2 = 0.0;
}