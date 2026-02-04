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
    for (int j = 1; j <= 2; j++) {
        sum *= ex;
        sum += (1. + 2. / xk + 2. / (xk * xk)) / rk;
        rk -= 1.;
        xk -= x;
    }
}
}
