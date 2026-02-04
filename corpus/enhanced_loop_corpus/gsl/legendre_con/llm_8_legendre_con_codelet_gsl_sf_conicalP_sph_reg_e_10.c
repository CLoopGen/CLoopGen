#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  double lambda;
extern  double xi;
extern double Pellp1;
extern double Pell;
extern double Pellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ell = l; ell >= 0; ell--) {
    double d1 = (ell + 1.) * (ell + 1.);
    double d2 = lambda * lambda;
    double d = d1 + d2;
    double temp1 = (2. * ell + 1.) * xi;
    Pellm1 = temp1 * Pell - d * Pellp1;
    Pellp1 = Pell;
    Pell = Pellm1;
}
}
