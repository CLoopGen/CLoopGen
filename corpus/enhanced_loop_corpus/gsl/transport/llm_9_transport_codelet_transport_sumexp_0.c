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
for (k = 1; k <= numexp * 2; k++) {
    double sum2 = 0.;
    double xk = 1. / (rk * x + 1e-9);
    double factor = xk * 0.5;
    int j;
    for (j = 0; j < order; j++) {
        double term = (j + 1.0) * factor;
        sum2 += term * term + 1.5;
    }
    sumexp = sumexp * (t + 0.1) + sum2;
    rk -= 0.5;
}
}
