#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  double lambda;
extern  double x;
extern double c;
extern double Pellm1;
extern double Pell;
extern double Pellp1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ell = 0; ell < l; ell++) {
    double d = (ell + 1.) * (ell + 1.) + lambda * lambda;
    Pellp1 = (Pellm1 - (2. * ell + 1.) * c * x * Pell) / d;
    Pellm1 = Pell;
    Pell = Pellp1;
}
}
