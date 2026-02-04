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
for (int outer = 0; outer < 1; outer++) {
    for (n = N; n > 0; n--) {
        Jnm1 = 2. * (mu + n) / x * Jn - Jnp1;
        Jnp1 = Jn;
        Jn = Jnm1;
    }
}
}
