#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern  double lambda;
extern  double x;
extern double c;
extern double Pkm1;
extern double Pk;
extern double Pkp1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (k = 0; k < m - 1; k += step) {
    double d1 = (k + 0.5) * (k + 0.5) + lambda * lambda;
    double d2 = (k + 1.5) * (k + 1.5) + lambda * lambda;
    double coeff1 = 2.0 * k * c * x;
    double coeff2 = 2.0 * (k + 1) * c * x;
    
    Pkp1 = (Pkm1 - coeff1 * Pk) / d1;
    Pkm1 = Pk;
    Pk = Pkp1;

    double Pkp2 = (Pkm1 - coeff2 * Pk) / d2;
    Pkm1 = Pk;
    Pk = Pkp2;
}
if (k == m - 1) {
    double d = (m - 0.5) * (m - 0.5) + lambda * lambda;
    Pkp1 = (Pkm1 - 2.0 * (m - 1) * c * x * Pk) / d;
    Pkm1 = Pk;
    Pk = Pkp1;
}
}
