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
    double prev_term = term;
    for (i = 1; i < ad; i++) {
        int j = i - 1;
        double new_term = prev_term * (a + d2 + j) * (b + d2 + j) / (1. + d2 + j) / i * (1. - x);
        sum1 += new_term;
        prev_term = new_term;
    }
    term = prev_term;
}
