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
double temp_array[2] = {Pellm1, Pell};
for (ell = 0; ell < l; ell++) {
    double d = (ell + 1.) * (ell + 1.) + lambda * lambda;
    double next_val = (temp_array[0] - (2. * ell + 1.) * c * x * temp_array[1]) / d;
    temp_array[0] = temp_array[1];
    temp_array[1] = next_val;
}
Pellm1 = temp_array[0];
Pell = temp_array[1];
Pellp1 = temp_array[1];
}
