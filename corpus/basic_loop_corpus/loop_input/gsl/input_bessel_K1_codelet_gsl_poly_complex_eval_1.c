#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[1 << 20]; // ~8MB array (1M doubles), sufficient for ~0.01 sec runtime
int len = 1 << 20; // length matches array size
gsl_complex z;
int i;
gsl_complex ans;

void init_vars() {
    // Initialize z and ans to non-zero values to ensure meaningful computation
    z.dat[0] = 1.5;
    z.dat[1] = -0.8;
    ans.dat[0] = 1.0;
    ans.dat[1] = 0.0;

    // Initialize large array c with simple pattern
    for (int j = 0; j < len; j++) {
        c[j] = (double)(j & 0xFF) * 0.01;
    }
}