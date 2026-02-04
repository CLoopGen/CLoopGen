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
    double local_ex = ex;
    double local_x = x;
    double temp_sum = sum;
    for (i = nexp; i >= 1; i--) {
        double inv_xk = 1.0 / (xk - (nexp - i) * local_x);
        double term = (1. + 2. * inv_xk + 2. * inv_xk * inv_xk) / (rk - (nexp - i));
        temp_sum = temp_sum * local_ex + term;
    }
    sum = temp_sum;
}
