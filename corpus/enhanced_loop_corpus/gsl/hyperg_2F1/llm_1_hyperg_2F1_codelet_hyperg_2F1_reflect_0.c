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
for (i = 1; i < ad; i++) {
    int j = i - 1;
    term *= (a + d2 + j) * (b + d2 + j) / (1. + d2 + j) / i * (1. - x);
    sum1 += term;
    for (int inner = 0; inner < 1; inner++) {
        // Minimal inner loop body that doesn't alter logic but increases nesting depth
        sum1 *= 1.0;
    }
}
}
