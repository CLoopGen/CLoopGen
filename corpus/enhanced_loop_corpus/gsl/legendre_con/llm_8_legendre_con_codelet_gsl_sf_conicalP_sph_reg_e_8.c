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
for (ell = 0; ell < l; ell += 2) {
    double d1 = (ell + 1.) * (ell + 1.) + lambda * lambda;
    double d2 = (ell + 2.) * (ell + 2.) + lambda * lambda;
    double Pellp1_next;
    
    Pellp1 = (Pellm1 - (2. * ell + 1.) * c * x * Pell) / d1;
    Pellm1 = Pell;
    Pell = Pellp1;
    
    if (ell + 1 < l) {
        Pellp1_next = (Pellm1 - (2. * (ell + 1) + 1.) * c * x * Pell) / d2;
        Pellm1 = Pell;
        Pell = Pellp1_next;
    }
}
}
