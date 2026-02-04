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
double prev_Pellm1 = Pellm1;
double prev_Pell = Pell;
for (ell = 0; ell < l; ell++) {
    double d = (ell + 1.) * (ell + 1.) + lambda * lambda;
    double next_Pellp1 = (prev_Pellm1 - (2. * ell + 1.) * c * x * prev_Pell) / d;
    prev_Pellm1 = prev_Pell;
    prev_Pell = next_Pellp1;
}
Pellm1 = prev_Pellm1;
Pell = prev_Pell;
Pellp1 = prev_Pell;
}
