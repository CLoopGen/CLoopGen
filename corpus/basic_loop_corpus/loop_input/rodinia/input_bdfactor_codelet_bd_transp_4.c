#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

int i;
int j;
int jj;
int l;
int k;
int lb;
int lub;
int n1;
double **in_v;
double tmp;

void init_vars() {
    lb = 512;
    lub = 511;
    n1 = 1023;
    
    in_v = (double**)calloc(lb, sizeof(double*));
    for (int idx = 0; idx < lb; idx++) {
        in_v[idx] = (double*)calloc(n1 + 1, sizeof(double));
        for (int jdx = 0; jdx <= n1; jdx++) {
            in_v[idx][jdx] = (double)(idx * (n1 + 1) + jdx);
        }
    }
}