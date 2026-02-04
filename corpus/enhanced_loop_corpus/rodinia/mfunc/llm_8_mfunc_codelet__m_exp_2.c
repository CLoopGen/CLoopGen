#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double eps;
extern int q;
extern double eqq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (q = 1; eqq > eps && q < 1000; q++) {
        double temp1 = 2.0 * q + 1.0;
        double temp2 = 2.0 * q + 3.0;
        double denominator = 16.0 * temp1 * temp2;
        eqq /= denominator;
        eqq *= (1.0 + 1.0/(q + 1.0)); // Additional computation to increase arithmetic intensity
    }
}
