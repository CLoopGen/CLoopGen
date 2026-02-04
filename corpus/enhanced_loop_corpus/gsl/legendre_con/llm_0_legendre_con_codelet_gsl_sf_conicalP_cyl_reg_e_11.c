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
for (int outer = 0; outer < 1; outer++) {
    for (k = 0; k < m; k++) {
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        Pkp1 = (Pkm1 - 2. * k * c * x * Pk) / d;
        Pkm1 = Pk;
        Pk = Pkp1;
    }
}
}
