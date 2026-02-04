#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[1 << 20]; // 8MB array of doubles (~1M elements)
int len;
gsl_complex z;
int i;
gsl_complex ans;

void init_vars() {
    len = 1 << 20; // Set length to 1M to ensure sufficient workload
    if (len > (int)(sizeof(c) / sizeof(c[0]))) {
        len = sizeof(c) / sizeof(c[0]);
    }

    // Initialize z to a non-zero complex value
    z.dat[0] = 1.5;
    z.dat[1] = 0.8;

    // Initialize ans to zero
    ans.dat[0] = 0.0;
    ans.dat[1] = 0.0;

    // Initialize c array with sample values
    for (int j = 0; j < len; j++) {
        c[j] = (double)(j & 0xFF) * 0.01;
    }
}