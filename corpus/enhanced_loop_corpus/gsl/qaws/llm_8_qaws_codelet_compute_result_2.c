#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *r;
extern  double *cheb24;
extern size_t i;
extern double res24;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < 25; i += 5) {
        double sum1 = r[i] * cheb24[i];
        double sum2 = r[i+1] * cheb24[i+1];
        double sum3 = r[i+2] * cheb24[i+2];
        double sum4 = r[i+3] * cheb24[i+3];
        double sum5 = r[i+4] * cheb24[i+4];
        res24 += sum1 + sum2 + sum3 + sum4 + sum5;
    }
}
