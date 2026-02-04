#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[131072];  // ~1MB of data (131072 * sizeof(double) = 1,048,576 bytes)
int len;
gsl_complex z;
int i;
gsl_complex ans;

void init_vars() {
    len = 131072;
    z.dat[0] = 1.0;
    z.dat[1] = 0.5;
    ans.dat[0] = 1.0;
    ans.dat[1] = 0.0;

    for (int j = 0; j < len; j++) {
        c[j] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
}