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
    double temp_coef = coef;
    for (k = 1; k < 30; ++k) {
        temp_coef *= -x * x / k;
        double temp_del = temp_coef / (2. * k + 1.);
        e += temp_del;
    }
    coef = temp_coef;
}
