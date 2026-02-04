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
    double xk_inv1 = 1. / xk;
    double xk_inv2 = 1. / (xk - x);
    sum *= ex * ex;
    sum += (((((120. * xk_inv1 + 120.) * xk_inv1 + 60.) * xk_inv1 + 20.) * xk_inv1 + 5.) * xk_inv1 + 1.) / rk;
    sum += (((((120. * xk_inv2 + 120.) * xk_inv2 + 60.) * xk_inv2 + 20.) * xk_inv2 + 5.) * xk_inv2 + 1.) / (rk - 1.);
    rk -= 2.;
    xk -= 2. * x;
}
}
