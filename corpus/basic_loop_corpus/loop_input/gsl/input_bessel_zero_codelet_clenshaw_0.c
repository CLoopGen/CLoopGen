#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *c;
int N = 1 << 20; // Approximately 8MB of data (1M doubles), adjust for ~0.01 sec runtime
double u = 0.75;
double B_np1 = 1.0;
double B_n = 0.5;
double B_nm1;
int n;

void init_vars() {
    c = (double *)aligned_alloc(32, N * sizeof(double));
    if (!c) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        c[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Random values between -1 and 1
    }
}