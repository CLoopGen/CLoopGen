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
    double accumulated_correction = 0.0;
    double factor = 1.0;
    for (i = nexp; i >= 1; i--) {
        double xk_inv = 1. / xk;
        sum *= ex;
        double poly = ((((((720. * xk_inv + 720.) * xk_inv + 360.) * xk_inv + 120.) * xk_inv + 30.) * xk_inv + 6.) * xk_inv + 1.);
        accumulated_correction += poly / rk;
        rk -= 1.;
        xk -= x;
        factor *= ex;
    }
    sum += accumulated_correction;
}
