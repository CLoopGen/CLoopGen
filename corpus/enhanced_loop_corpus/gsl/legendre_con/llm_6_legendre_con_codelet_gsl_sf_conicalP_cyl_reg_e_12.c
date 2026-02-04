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
for (k = m; k > 0; k--) {
    double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
    double temp1 = 2. * k * xi * Pk;
    double temp2 = d * Pkp1;
    Pkm1 = temp1 + temp2;
    Pkp1 = Pk;
    Pk = Pkm1;
}
}
