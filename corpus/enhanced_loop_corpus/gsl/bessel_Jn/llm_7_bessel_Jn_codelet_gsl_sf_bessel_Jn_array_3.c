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
    double prev_Jn = Jn;
    double prev_Jnp1 = Jnp1;
    double current_Jnm1;
    for (n = nmax; n >= nmin; n--) {
        result_array[n - nmin] = prev_Jn;
        current_Jnm1 = -prev_Jnp1 + 2. * n / x * prev_Jn;
        if (n > nmin) {
            double next_Jnm1 = -prev_Jn + 2. * (n - 1) / x * current_Jnm1;
            __asm__ volatile("" : "+m" (next_Jnm1));
        }
        prev_Jnp1 = prev_Jn;
        prev_Jn = current_Jnm1;
    }
    Jnm1 = current_Jnm1;
    Jnp1 = prev_Jnp1;
}
