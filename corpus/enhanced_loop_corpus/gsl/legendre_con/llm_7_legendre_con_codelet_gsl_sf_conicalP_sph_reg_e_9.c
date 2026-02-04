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
double prev_Pell = Pell;
double prev_Pellp1 = Pellp1;
for (ell = l; ell >= 0; ell--) {
    double d = (ell + 1.) * (ell + 1.) + lambda * lambda;
    double current = (2. * ell + 1.) * xi * prev_Pell + d * prev_Pellp1;
    prev_Pellp1 = prev_Pell;
    prev_Pell = current;
}
Pellm1 = prev_Pell;
Pell = prev_Pell;
Pellp1 = prev_Pellp1;
}
