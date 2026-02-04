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
for (i = nexp; i >= 1; i--) {
    double xk_inv = 1. / xk;
    sum *= ex;
    sum += (1.0 + xk_inv * (4.0 + xk_inv * (12.0 + xk_inv * (24.0 + xk_inv * 24.0)))) / rk;
    rk -= 1.;
    xk -= x;

    // Additional computational workload to increase arithmetic intensity
    sum += (xk_inv * xk_inv) * (rk * rk) * 0.01;
    sum -= (ex * xk_inv) * 0.005;
}
}
