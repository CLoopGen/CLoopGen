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
    double prev_yellm1 = yellm1;
    double prev_yell = yell;
    double current_yellp1;
    for (ell = 1; ell < lmax; ell++) {
        current_yellp1 = (2 * ell + 1) / x * prev_yell - prev_yellm1;
        result_array[ell + 1] = current_yellp1;
        prev_yellm1 = prev_yell;
        prev_yell = current_yellp1;
    }
    yellm1 = prev_yellm1;
    yell = prev_yell;
}
