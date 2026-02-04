#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>

int Np;
double *t;
double increment;
int i;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    increment = 1.5;

    size_t data_size = 128 * 1024 * 1024; 
    Np = data_size / sizeof(double);

    t = (double*)aligned_alloc(32, Np * sizeof(double));
    if (!t) {
        exit(1);
    }

    do {
        for (i = 0; i < Np; i++) {
            t[i] = increment * (double)i;
        }
        gettimeofday(&end, NULL);
    } while ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6 < 0.01);
}