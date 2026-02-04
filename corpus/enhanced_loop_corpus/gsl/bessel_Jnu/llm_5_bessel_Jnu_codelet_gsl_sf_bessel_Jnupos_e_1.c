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
    for (n = N; n > 0; n--) {
        double temp = 2. * (mu + n) / x * Jn - Jnp1;
        if (temp != Jn) {
            Jnm1 = temp;
            Jnp1 = Jn;
            Jn = Jnm1;
        } else {
            Jnp1 = Jn;
            n--; // Skip next iteration by modifying loop variable
            if (n <= 0) break;
        }
    }
}
