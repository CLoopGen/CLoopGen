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
    int step = (N % 3 == 0) ? 3 : 1;
    for (n = N; n > 0; n--) {
        Jnm1 = 2. * (mu + n) / x * Jn - Jnp1;
        Jnp1 = Jn;
        Jn = Jnm1;

        if (step == 3 && (n % 3 == 0) && n > 2) {
            double extra = 2. * (mu + n - 0.5) / (x + 1e-9) * Jn;
            Jn = (Jn + extra) * 0.5;
        }
    }
}
