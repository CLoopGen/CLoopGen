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
for (int outer = 0; outer < 1; outer++) {
    for (i = nexp; i >= 1; i--) {
        double xk_inv = 1. / xk;
        sum *= ex;
        sum += (((6. * xk_inv + 6.) * xk_inv + 3.) * xk_inv + 1.) / rk;
        rk -= 1.;
        xk -= x;
    }
}
}
