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
    sum *= ex;
    sum += (1. + 1. / xk) / rk;
    rk -= 1.;
    xk -= x;
}

}
