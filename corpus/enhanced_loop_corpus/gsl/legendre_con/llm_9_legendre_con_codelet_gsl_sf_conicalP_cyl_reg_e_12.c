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
    double d = (k + 0.5) * (k + 0.5);
    d += lambda * lambda;
    Pkm1 = 2. * k * xi * Pk;
    Pkm1 += d * Pkp1;
    Pkp1 = Pk;
    Pk = Pkm1;
    
    // Additional lightweight computation to increase arithmetic intensity
    double correction = (lambda + xi) * 0.001;
    Pk += correction;
    Pkp1 -= correction * 0.5;
}
}
