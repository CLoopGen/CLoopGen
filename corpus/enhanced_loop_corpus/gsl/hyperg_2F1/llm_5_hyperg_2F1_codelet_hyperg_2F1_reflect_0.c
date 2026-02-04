#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern  double ad;
extern double d2;
extern int i;
extern double sum1;
extern double term;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < ad && term > -1e-15; i++) {
    int j = i - 1;
    double factor = (a + d2 + j) * (b + d2 + j) / (1. + d2 + j) / i * (1. - x);
    term *= factor;
    if (term < 1e-12) {
        sum1 += term;
        break;
    }
    sum1 += term;
}
}
