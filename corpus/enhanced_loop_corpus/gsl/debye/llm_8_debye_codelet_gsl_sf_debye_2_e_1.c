#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern  int nexp;
extern  double ex;
extern double xk;
extern double rk;
extern double sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    int step = 2;
    for (i = nexp; i >= 1; i -= step) {
        sum *= ex;
        sum += (1. + 2. / xk + 2. / (xk * xk) + 3. / (xk * xk * xk)) / rk;
        sum += (1. + 2. / (xk - x) + 2. / ((xk - x) * (xk - x))) / (rk - 1.);
        rk -= 2.;
        xk -= 2. * x;
    }
}
