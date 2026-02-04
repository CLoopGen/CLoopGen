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
    double temp_Jnp1 = Jnp1;
    double temp_Jn = Jn;
    for (n = N; n > 0; n--) {
        double temp_Jnm1 = 2. * (mu + n) / x * temp_Jn - temp_Jnp1;
        temp_Jnp1 = temp_Jn;
        temp_Jn = temp_Jnm1;
    }
    Jnm1 = temp_Jn;
    Jnp1 = temp_Jnp1;
}
