#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[131072]; // ~1MB of data (131072 * 8 bytes)
int len;
gsl_complex z;
int i;
gsl_complex ans;

void init_vars() {
    len = 131072;
    
    // Initialize array c with non-trivial values
    for (int j = 0; j < len; j++) {
        c[j] = (double)(j % 100) / 10.0;
    }
    
    // Initialize complex numbers
    z.dat[0] = 1.5;
    z.dat[1] = -0.8;
    ans.dat[0] = 1.0;
    ans.dat[1] = 0.0;
}