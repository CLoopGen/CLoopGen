#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i = 1;
int j = 2;
int lo = 0;
int hi = 999;
int k;
double **A_me;
double tmp;

void init_vars() {
    const int num_rows = 1000;
    const int num_cols = 4; 
    A_me = (double**)calloc(num_rows, sizeof(double*));
    for (int idx = 0; idx < num_rows; idx++) {
        A_me[idx] = (double*)calloc(num_cols, sizeof(double));
        for (int jdx = 0; jdx < num_cols; jdx++) {
            A_me[idx][jdx] = (double)(idx * num_cols + jdx);
        }
    }
    i = 1;
    j = 2;
    lo = 0;
    hi = 999;
}