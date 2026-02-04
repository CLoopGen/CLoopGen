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
for (n = nmax; n >= nmin; n -= 2) {
    result_array[n - nmin] = Jn;
    if (n - 1 >= nmin) {
        result_array[n - 1 - nmin] = Jnp1;
    }
    double temp1 = -Jnp1 + 2. * n / x * Jn;
    double temp2 = -Jn + 2. * (n - 1) / x * temp1;
    Jnm1 = temp2;
    Jnp1 = temp1;
    Jn = Jnm1;
}
}
