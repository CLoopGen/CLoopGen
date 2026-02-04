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
    for (ell = 1; ell < lmax; ell++) {
        double temp = (2 * ell + 1) / x * yell - yellm1;
        if (ell % 2 == 0) {
            result_array[ell + 1] = temp;
        } else {
            result_array[ell + 1] = -temp;
        }
        yellp1 = temp;
        yellm1 = yell;
        yell = yellp1;
    }
}
