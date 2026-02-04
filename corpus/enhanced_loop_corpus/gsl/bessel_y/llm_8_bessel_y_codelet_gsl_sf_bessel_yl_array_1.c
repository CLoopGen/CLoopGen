#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_array;
extern double yellp1;
extern double yell;
extern double yellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ell = 1; ell < lmax; ell += 2) {
    if (ell + 1 < lmax) {
        double temp1, temp2;
        temp1 = (2 * ell + 1) / x * yell - yellm1;
        temp2 = (2 * (ell + 1) + 1) / x * temp1 - yell;
        result_array[ell + 1] = temp1;
        result_array[ell + 2] = temp2;
        yellm1 = temp1;
        yell = temp2;
    } else {
        yellp1 = (2 * ell + 1) / x * yell - yellm1;
        result_array[ell + 1] = yellp1;
        yellm1 = yell;
        yell = yellp1;
    }
}
}
