#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[1 << 20]; // ~8MB of data (1M doubles), sufficient for ~0.01 sec runtime
int len = 1 << 20;
gsl_complex z = {{1.5, 0.5}};
int i;
gsl_complex ans = {{0.0, 0.0}};

void init_vars() {
    for (int j = 0; j < len; j++) {
        c[j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Random values in [-1, 1]
    }
    z.dat[0] = 1.5;
    z.dat[1] = 0.5;
    ans.dat[0] = 0.0;
    ans.dat[1] = 0.0;
}