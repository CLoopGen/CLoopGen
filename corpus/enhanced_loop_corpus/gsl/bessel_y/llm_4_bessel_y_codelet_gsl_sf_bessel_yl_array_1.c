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
        if (yellp1 > 0.0) {
            yellp1 = (2 * ell + 1) / x * yell - yellm1;
        } else {
            yellp1 = ((2 * ell + 1) * yell - x * yellm1) / x;
        }
        result_array[ell + 1] = yellp1;
        yellm1 = yell;
        yell = yellp1;
    }
}
