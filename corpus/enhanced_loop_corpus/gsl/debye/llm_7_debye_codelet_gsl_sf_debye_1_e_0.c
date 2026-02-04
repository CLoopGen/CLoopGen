#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern  int nexp;
extern  double ex;
extern double sum;
extern double xk;
extern double rk;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = sum;
    for (i = nexp; i >= 1; i--) {
        double inv_xk = 1.0 / (xk - x * (nexp - i)); // Remove WAW and RAW by precomputing offset
        double term = (1. + inv_xk) / (rk - (nexp - i));
        local_sum = local_sum * ex + term;
    }
    sum = local_sum; // Update only final value, eliminating loop-carried dependency on sum update
    // rk and xk are not updated per iteration — breaks loop-carried dependencies on rk and xk
}
