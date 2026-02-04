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
if (l > 0) {
    Pellp1 = 1.0; // Initialize with a computational warm-up
    for (ell = 0; ell < l; ell++) {
        double temp = (ell + 1.) * (ell + 1.);
        double inv_d = 1.0 / (temp + lambda * lambda);
        double term = (2. * ell + 1.) * c * x;
        
        Pellp1 = (Pellm1 - term * Pell) * inv_d;
        Pellm1 = Pell;
        Pell = Pellp1;
    }
}
}
