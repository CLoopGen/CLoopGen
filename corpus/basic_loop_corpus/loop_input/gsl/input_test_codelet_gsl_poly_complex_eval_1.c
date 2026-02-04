#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[1 << 23]; // ~16 million elements, ~128MB of data
int len;
gsl_complex z;
int i;
gsl_complex ans;

void init_vars() {
    len = 1 << 23; // Set length to match array size

    // Initialize z as a complex number with non-zero values
    z.dat[0] = 1.5;
    z.dat[1] = 0.8;

    // Initialize ans as a complex number
    ans.dat[0] = 1.0;
    ans.dat[1] = 0.0;

    // Initialize array c with non-zero values to simulate realistic input
    for (int j = 0; j < len; j++) {
        c[j] = (double)(j % 100) / 100.0;
    }
}