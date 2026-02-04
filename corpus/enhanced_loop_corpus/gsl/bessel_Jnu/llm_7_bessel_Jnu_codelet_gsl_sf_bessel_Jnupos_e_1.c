#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int N;
extern double mu;
extern double Jnp1;
extern double Jn;
extern double Jnm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_Jnp1 = Jnp1;
    double prev_Jn = Jn;
    double next_Jnm1;
    for (n = N; n > 0; n--) {
        if (n == N) {
            next_Jnm1 = 2. * (mu + n) / x * prev_Jn - prev_Jnp1;
        } else {
            double temp = 2. * (mu + n) / x * prev_Jn - prev_Jnp1;
            prev_Jnp1 = prev_Jn;
            prev_Jn = temp;
        }
    }
    Jnm1 = (N == 1) ? (2. * (mu + 1) / x * Jn - Jnp1) : next_Jnm1;
    if (N > 1) {
        Jn = next_Jnm1;
        Jnp1 = prev_Jn;
    }
}
