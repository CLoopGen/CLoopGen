#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

double *r0;
int Np;
int i;
double *r;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    Np = 134217728; // 134217728 doubles = 1GB / 8 bytes per double = ~128MB of data, allows loop to run around 0.01s on modern CPUs

    r0 = (double *)aligned_alloc(32, Np * sizeof(double));
    r = (double *)aligned_alloc(32, Np * sizeof(double));

    if (!r0 || !r) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < Np; j++) {
        r0[j] = (double)(j % 1000) + 0.5;
        r[j] = 0.0;
    }

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    if (elapsed > 0.015) {
        Np = (int)(Np * 0.015 / elapsed);
        free(r0);
        free(r);
        r0 = (double *)aligned_alloc(32, Np * sizeof(double));
        r = (double *)aligned_alloc(32, Np * sizeof(double));
        for (int j = 0; j < Np; j++) {
            r0[j] = (double)(j % 1000) + 0.5;
            r[j] = 0.0;
        }
    }
}