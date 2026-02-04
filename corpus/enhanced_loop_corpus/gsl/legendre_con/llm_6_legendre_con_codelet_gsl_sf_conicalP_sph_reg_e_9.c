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
    double d = (ell + 1.) * (ell + 1.) + lambda * lambda;
    double temp = (2. * ell + 1.) * xi * Pell + d * Pellp1;
    Pellm1 = temp;
    Pellp1 = Pell;
    Pell = temp;
}
}
