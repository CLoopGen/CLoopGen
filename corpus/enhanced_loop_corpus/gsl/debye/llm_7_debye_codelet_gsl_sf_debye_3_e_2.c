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
    double local_sum = sum;
    double accumulator = 0.0;
    double rk_temp = rk;
    double xk_temp = xk;
    for (i = nexp; i >= 1; i--) {
        double xk_inv = 1. / xk_temp;
        accumulator += (((6. * xk_inv + 6.) * xk_inv + 3.) * xk_inv + 1.) / rk_temp;
        rk_temp -= 1.;
        xk_temp -= x;
    }
    for (int j = 0; j < nexp; j++) {
        local_sum *= ex;
    }
    sum = local_sum + accumulator;
}
