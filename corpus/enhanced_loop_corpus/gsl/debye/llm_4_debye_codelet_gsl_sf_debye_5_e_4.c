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
    if (xk == 0.0) continue;
    double xk_inv = 1. / xk;
    sum *= ex;
    sum += (((((120. * xk_inv + 120.) * xk_inv + 60.) * xk_inv + 20.) * xk_inv + 5.) * xk_inv + 1.) / rk;
    rk -= 1.;
    xk -= x;
}
}
