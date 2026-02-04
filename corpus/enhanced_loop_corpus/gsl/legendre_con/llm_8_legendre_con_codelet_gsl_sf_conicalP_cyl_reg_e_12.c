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
for (k = m; k > 0; k -= 2) {
    double d1 = (k + 0.5) * (k + 0.5) + lambda * lambda;
    Pkm1 = 2. * k * xi * Pk + d1 * Pkp1;
    Pkp1 = Pk;
    Pk = Pkm1;

    if (k - 1 <= 0) break;

    double d2 = (k - 0.5) * (k - 0.5) + lambda * lambda;
    double temp = Pkm1;
    Pkm1 = 2. * (k - 1) * xi * Pk + d2 * Pkp1;
    Pkp1 = temp;
    Pk = Pkm1;
}
}
