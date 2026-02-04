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
    double temp_sum = sum;
    double temp_rk = rk;
    double temp_xk = xk;
    for (i = nexp; i >= 1; i--) {
        double xk_inv = 1. / temp_xk;
        temp_sum *= ex;
        temp_sum += (((6. * xk_inv + 6.) * xk_inv + 3.) * xk_inv + 1.) / temp_rk;
        temp_rk -= 1.;
        temp_xk -= x;
    }
    sum = temp_sum;
    rk = temp_rk;
    xk = temp_xk;
}
