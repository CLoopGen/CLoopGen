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
for (k = 0; k < m && m > 0; k++) {
    double temp1 = (k + 0.5) * (k + 0.5);
    double temp2 = lambda * lambda;
    double d = temp1 + temp2;
    double coeff = 2.0 * k * c * x;
    Pkp1 = (Pkm1 - coeff * Pk) / d;
    Pkm1 = Pk;
    Pk = Pkp1;
}
}
