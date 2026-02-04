#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern  double lambda;
extern  double xi;
extern double Pkp1;
extern double Pk;
extern double Pkm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_d, prev_xi_term;
    double buffer[3] = {Pkp1, Pk, 0.0};
    for (k = m; k > -1; k--) {
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        double xiterm = 2. * k * xi;
        if (k != m) {
            buffer[2] = xiterm * buffer[1] - prev_d * buffer[0];
        } else {
            buffer[2] = 2. * k * xi * Pk - d * Pkp1;
        }
        prev_d = d;
        prev_xi_term = xiterm;
        buffer[0] = buffer[1];
        buffer[1] = buffer[2];
    }
    Pkm1 = buffer[2];
    Pk = buffer[1];
    Pkp1 = buffer[0];
}
