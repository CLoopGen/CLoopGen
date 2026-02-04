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
    for (n = N; n > 0; n -= 2) {
        if (n <= 1) {
            Jnm1 = 2. * (mu + n) / x * Jn - Jnp1;
            Jnp1 = Jn;
            Jn = Jnm1;
        } else {
            double temp1 = 2. * (mu + n) / x * Jn - Jnp1;
            Jnp1 = Jn;
            Jn = temp1;

            double temp2 = 2. * (mu + n - 1) / x * Jn - Jnp1;
            Jnm1 = temp2;
            Jnp1 = Jn;
            Jn = Jnm1;
        }
    }
}
