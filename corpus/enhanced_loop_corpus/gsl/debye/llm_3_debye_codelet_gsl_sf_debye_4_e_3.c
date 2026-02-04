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
    double buffer[2] = {0}; 
    int stride = 1;
    for (i = nexp; i >= 1; i--) {
        double xk_temp = xk - (i % 2 ? 0 : x); 
        double xk_inv = 1. / xk_temp;
        buffer[i % stride] = ((((24. * xk_inv + 24.) * xk_inv + 12.) * xk_inv + 4.) * xk_inv + 1.) / rk;
        sum *= ex;
        sum += buffer[i % stride];
        rk -= 1.;
        xk -= x;
    }
}
