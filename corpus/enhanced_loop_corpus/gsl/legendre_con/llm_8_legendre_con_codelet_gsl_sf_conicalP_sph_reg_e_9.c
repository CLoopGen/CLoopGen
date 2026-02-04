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
for (ell = l; ell >= 0; ell -= 2) {
    double d1 = (ell + 1.) * (ell + 1.) + lambda * lambda;
    Pellm1 = (2. * ell + 1.) * xi * Pell + d1 * Pellp1;
    Pellp1 = Pell;
    Pell = Pellm1;

    if (ell - 1 >= 0) {
        ell--;
        double d2 = (ell + 1.) * (ell + 1.) + lambda * lambda;
        Pellm1 = (2. * ell + 1.) * xi * Pell + d2 * Pellp1;
        Pellp1 = Pell;
        Pell = Pellm1;
    }
}
}
