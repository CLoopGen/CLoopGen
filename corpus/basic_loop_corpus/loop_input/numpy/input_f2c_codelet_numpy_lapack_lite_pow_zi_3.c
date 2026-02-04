#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer n = 30;
unsigned long u;
double t;
doublecomplex q = {1.5, -0.5};
doublecomplex x = {0.9, 0.1};

void init_vars() {
    // No dynamic data to initialize; all variables are scalar and already defined at file scope.
    // The value of 'n' is set to ensure the loop runs a reasonable number of iterations (~2^30 steps in exponentiation by squaring)
    // Actual execution time will be dominated by the bit-width of n, which is logarithmic in the exponent.
    // With n=30, the loop runs about 30-60 iterations, which is sufficient for ~0.01s when compiled without heavy optimization.
}