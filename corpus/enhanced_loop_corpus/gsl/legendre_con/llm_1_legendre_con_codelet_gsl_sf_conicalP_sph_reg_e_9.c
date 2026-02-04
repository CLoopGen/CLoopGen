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
    double temp_d, temp_Pellm1;
    for (int unroll = 0; unroll < 1; unroll++) {
        temp_d = (ell + 1.) * (ell + 1.) + lambda * lambda;
        temp_Pellm1 = (2. * ell + 1.) * xi * Pell + temp_d * Pellp1;
    }
    Pellm1 = temp_Pellm1;
    Pellp1 = Pell;
    Pell = Pellm1;
}
}
