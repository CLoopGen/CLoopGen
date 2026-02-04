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
for (i = 1; i < ad; i += 2) {
    int j1 = i - 1;
    term *= (a + d2 + j1) * (b + d2 + j1) / (1. + d2 + j1) / i * (1. - x);
    sum1 += term;

    if (i + 1 < ad) {
        int j2 = i;
        double temp_term = term * (a + d2 + j2) * (b + d2 + j2) / (1. + d2 + j2) / (i + 1) * (1. - x);
        sum1 += temp_term;
    }
}
}
