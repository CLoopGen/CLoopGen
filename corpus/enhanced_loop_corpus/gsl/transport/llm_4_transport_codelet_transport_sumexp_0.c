#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int numexp;
extern  int order;
extern  double t;
extern double x;
extern double rk;
extern double sumexp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= numexp; k++) {
    double sum2 = 1.;
    double xk = 1. / (rk * x);
    double xk1 = 1.;
    int j;
    for (j = 1; j <= order; j++) {
        if (xk1 > 0.5) {
            sum2 = sum2 * xk1 * xk + 1.;
        }
        xk1 += 1.;
    }
    sumexp *= t;
    sumexp += sum2;
    rk -= 1.;
}
}
