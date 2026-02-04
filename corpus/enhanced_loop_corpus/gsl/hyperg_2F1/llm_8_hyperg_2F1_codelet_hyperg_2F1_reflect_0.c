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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (i = 1; i < ad / 2; i++) {
        int j = i - 1;
        double temp1 = (a + d2 + j) * (b + d2 + j);
        double temp2 = (1. + d2 + j) * i;
        term *= temp1 / temp2 * (1. - x);
        term += (a * b) / (x + 1e-9);  // Additional computation to increase intensity
        sum1 += term * term;  // Squaring term to add complexity
    }
}
