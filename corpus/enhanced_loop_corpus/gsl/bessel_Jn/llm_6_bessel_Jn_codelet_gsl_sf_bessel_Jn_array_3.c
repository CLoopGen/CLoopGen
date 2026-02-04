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
    double temp_Jn = Jn;
    double temp_Jnp1 = Jnp1;
    for (n = nmax; n >= nmin; n--) {
        result_array[n - nmin] = temp_Jn;
        double temp_Jnm1 = -temp_Jnp1 + 2. * n / x * temp_Jn;
        temp_Jnp1 = temp_Jn;
        temp_Jn = temp_Jnm1;
    }
    Jnm1 = temp_Jn;
    Jnp1 = temp_Jnp1;
}
