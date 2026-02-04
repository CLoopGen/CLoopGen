#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double (*matrix)[3];
double *r;
int n = 1000000;  // Size chosen to achieve ~0.01 sec runtime

void init_vars() {
    matrix = (double (*)[3])calloc(n, sizeof(*matrix));
    r = (double *)calloc(n, sizeof(double));

    // Initialize matrix and r with non-zero values to avoid division by zero
    for (int idx = 0; idx < n; idx++) {
        matrix[idx][0] = 0.1 + idx * 0.0001;
        matrix[idx][1] = 1.0 + idx * 0.0002;
        matrix[idx][2] = 0.2 + idx * 0.0003;
        r[idx] = 1.0 + idx * 0.0004;
    }

    // Ensure first element is safe for use in loop starting at i=1
    matrix[0][2] = 0.5;
    r[0] = 1.0;

    i = 0;  // Reset i to ensure safe entry into loop
}