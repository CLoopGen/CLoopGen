#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int i;
int j;
int jj;
int l;
int lb;
int ub;
int lub;
int n1;
double **in_v;
int p;
int pp;
int lbi;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on empirical tuning, n1 around 4096 provides reasonable timing
    n1 = 4096;
    lb = 0;
    ub = n1;
    lub = n1;

    // Allocate 2D array in_v with dimensions (lub+1) x (n1+1)
    in_v = (double**)calloc(lub + 1, sizeof(double*));
    if (!in_v) exit(1);

    for (int idx = 0; idx <= lub; idx++) {
        in_v[idx] = (double*)malloc((n1 + 1) * sizeof(double));
        if (!in_v[idx]) exit(1);
        // Initialize with known pattern to avoid undefined behavior
        for (int jdx = 0; jdx <= n1; jdx++) {
            in_v[idx][jdx] = (double)(idx * (n1 + 1) + jdx + 1);
        }
    }
}