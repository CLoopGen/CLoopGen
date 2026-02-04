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
    double temp_xk = xk + (i - 1) * x; // Introduce anti-dependence by using future xk value early
    double xk_inv = 1. / temp_xk;
    double term = (((((120. * xk_inv + 120.) * xk_inv + 60.) * xk_inv + 20.) * xk_inv + 5.) * xk_inv + 1.) / rk;
    sum *= ex;
    sum += term;
    // Modify rk and xk in reverse order to create WAR dependency
    double next_rk = rk - 1.;
    xk = temp_xk - x; // Reassign xk after using modified version
    rk = next_rk;
}
}
