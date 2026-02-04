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
double terms[2] = {term, 0.0};
double sums[2] = {sum1, 0.0};
int idx = 0;

for (i = 1; i < ad; i++) {
    int j = i - 1;
    terms[1 - idx] = terms[idx] * (a + d2 + j) * (b + d2 + j) / (1. + d2 + j) / i * (1. - x);
    sums[1 - idx] = sums[idx] + terms[1 - idx];
    idx = 1 - idx;
}

term = terms[idx];
sum1 = sums[idx];
}
