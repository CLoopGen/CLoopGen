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
double local_sum = sum; // Remove loop-carried dependence on 'sum' by using local accumulator
double local_rk = rk;
double local_xk = xk;

for (i = nexp; i >= 1; i--) {
    double xk_inv = 1. / local_xk;
    local_sum *= ex;
    local_sum += (((((120. * xk_inv + 120.) * xk_inv + 60.) * xk_inv + 20.) * xk_inv + 5.) * xk_inv + 1.) / local_rk;
    local_rk -= 1.;
    local_xk -= x;
}

// Write back final values to maintain semantics
sum = local_sum;
rk = local_rk;
xk = local_xk;
}
