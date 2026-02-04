#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int j;
int jj;
int lb;
int ub;
int n1;
double **in_v;

void init_vars() {
    i = 0;
    lb = 0;
    ub = 1000;
    n1 = 2000;

    int array_size = n1 + 1;
    in_v = (double**)calloc(array_size, sizeof(double*));
    if (!in_v) exit(1);

    for (int idx = 0; idx < array_size; idx++) {
        in_v[idx] = (double*)calloc(array_size, sizeof(double));
        if (!in_v[idx]) exit(1);
    }
}