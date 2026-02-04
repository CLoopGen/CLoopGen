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
        temp_sum *= ex;
        temp_sum += (1. + 2. / temp_xk + 2. / (temp_xk * temp_xk)) / temp_rk;
        temp_rk -= 1.;
        temp_xk -= x;
    }
    sum = temp_sum;
    rk = temp_rk;
    xk = temp_xk;
}
