#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double coef;
extern double e;
extern double del;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < 60; k += 2) {
        coef *= (-x * x) / k;
        coef *= (-x * x) / (k + 1);
        del = coef / (2. * k + 1.);
        e += del;
        del = coef * (-x * x) / ((k + 1) * (2. * k + 3.));
        e += del;
    }
}
