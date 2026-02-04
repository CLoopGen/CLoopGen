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
        sum *= ex;
        sum += ((((24. * xk_inv1 + 24.) * xk_inv1 + 12.) * xk_inv1 + 4.) * xk_inv1 + 1.) / rk;
        rk -= 1.;
        xk -= x;

        if (i - 1 >= 1) {
            double xk_inv2 = 1. / (xk - x);
            sum *= ex;
            sum += ((((24. * xk_inv2 + 24.) * xk_inv2 + 12.) * xk_inv2 + 4.) * xk_inv2 + 1.) / (rk - 1.);
            rk -= 1.;
            xk -= x;
        }
    }
}
