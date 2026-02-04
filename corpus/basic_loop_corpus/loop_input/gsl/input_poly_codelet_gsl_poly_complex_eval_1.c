#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[1 << 20]; // 8MB of data (1M doubles), adjust if needed for timing
int len = 1 << 20;
gsl_complex z = {{1.5, 0.5}};
int i;
gsl_complex ans = {{0.0, 0.0}};

void init_vars() {
    // Initialize array c with non-trivial values to avoid optimization away
    for (int j = 0; j < len; j++) {
        c[j] = ((double)j) * 0.0001;
    }
    // Ensure z and ans have defined state
    z.dat[0] = 1.5;
    z.dat[1] = 0.5;
    ans.dat[0] = 0.0;
    ans.dat[1] = 0.0;
    i = 0;
}