#include <stdio.h>
#include <inttypes.h>

int m = 1200;
int n = 1400;
double float_n = 1400.0;

double data[1400][1200];
double mean[1200];
int i;
int j;

void init_vars() {
    for (int i_inner = 0; i_inner < n; i_inner++) {
        for (int j_inner = 0; j_inner < m; j_inner++) {
            data[i_inner][j_inner] = (double)(i_inner + j_inner);
        }
    }
    for (int j_inner = 0; j_inner < m; j_inner++) {
        mean[j_inner] = 0.0;
    }
}