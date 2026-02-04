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
for (n = nmax; n >= nmin; n--) {
    result_array[n - nmin] = Jn;
    Jnm1 = -Jnp1 + 2. * n / x * Jn;
    Jnp1 = Jn;
    Jn = Jnm1;
}

}
