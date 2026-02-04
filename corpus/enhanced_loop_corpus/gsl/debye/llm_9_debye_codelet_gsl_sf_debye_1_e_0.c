#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern  int nexp;
extern  double ex;
extern double sum;
extern double xk;
extern double rk;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = nexp; i >= 1; i--) {
        sum = sum * ex + (1. + 1. / (xk)) / rk
                    + (1. + 1. / (xk - x)) / (rk - 1.)
                    + (1. + 1. / (xk - 2*x)) / (rk - 2.);
        rk -= 3.;
        xk -= 3. * x;
        i--; 
        if (i >= 1) i--;
    }
}
