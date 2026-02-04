#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double dat[2];
} gsl_complex;

double c[131072]; // ~1MB of data: 131072 * sizeof(double) = 1MB
int len;
gsl_complex z;
int i;
gsl_complex ans;

void init_vars() {
    len = 131072;
    
    // Initialize z to a typical complex value, e.g., (1.5, 0.8)
    z.dat[0] = 1.5;
    z.dat[1] = 0.8;
    
    // Initialize ans to zero
    ans.dat[0] = 0.0;
    ans.dat[1] = 0.0;
    
    // Initialize array c with non-trivial values to avoid optimization away
    for (int j = 0; j < len; j++) {
        c[j] = (double)(j & 1023) / 100.0; // Patterned but safe initialization without math functions
    }
}