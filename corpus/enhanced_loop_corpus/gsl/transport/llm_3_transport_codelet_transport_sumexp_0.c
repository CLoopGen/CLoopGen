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
double temp_sumexp = sumexp;
double temp_rk = rk;
for (k = 0; k < numexp; k++) {
    double sum2 = 1.;
    double xk = 1. / ((temp_rk - k) * x);
    double xk1 = 1.;
    int j;
    for (j = 0; j < order; j++) {
        sum2 = sum2 * xk1 * xk + 1.;
        xk1 += 1.;
    }
    temp_sumexp *= t;
    temp_sumexp += sum2;
}
sumexp = temp_sumexp;
rk = temp_rk - numexp;
}
