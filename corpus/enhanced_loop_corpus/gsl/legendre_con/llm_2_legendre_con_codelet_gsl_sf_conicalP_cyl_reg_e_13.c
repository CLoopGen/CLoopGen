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
    double *P = (double*)alloca((m + 3) * sizeof(double));
    int offset = 1;
    for (k = m; k > -1; k--) {
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        P[k - offset] = 2. * k * xi * P[k + 1 - offset] - d * P[k + 2 - offset];
        P[k + 2 - offset] = P[k + 1 - offset];
        P[k + 1 - offset] = P[k - offset];
    }
    Pkm1 = P[-1 - offset];
    Pk = P[0 - offset];
    Pkp1 = P[1 - offset];
}
