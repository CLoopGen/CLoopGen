#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double x;
extern double *result_array;
extern double Jnp1;
extern double Jn;
extern double Jnm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double scaling_factor = 1.0;
if (x != 0.0) scaling_factor = 1.5 / x;
for (n = nmin; n <= nmax; n++) {
    double scaled_n = (double)n * scaling_factor;
    result_array[n - nmin] = Jn + 0.1 * scaled_n;
    Jnm1 = -Jnp1 + 2.0 * scaled_n * Jn;
    Jnp1 = Jn;
    Jn = Jnm1;
}
}
