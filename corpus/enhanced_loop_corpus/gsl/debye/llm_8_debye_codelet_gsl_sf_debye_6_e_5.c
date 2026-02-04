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
for (i = nexp; i >= 1; i -= 2) {
    double xk_inv = 1. / xk;
    sum *= ex;
    sum += ((((((720. * xk_inv + 720.) * xk_inv + 360.) * xk_inv + 120.) * xk_inv + 30.) * xk_inv + 6.) * xk_inv + 1.) / rk;
    rk -= 1.;
    xk -= x;
    if (i - 1 >= 1) {
        double xk_inv_next = 1. / (xk - x);
        sum *= ex;
        sum += ((((((720. * xk_inv_next + 720.) * xk_inv_next + 360.) * xk_inv_next + 120.) * xk_inv_next + 30.) * xk_inv_next + 6.) * xk_inv_next + 1.) / (rk - 1.);
        rk -= 1.;
        xk -= x;
    }
}
}
