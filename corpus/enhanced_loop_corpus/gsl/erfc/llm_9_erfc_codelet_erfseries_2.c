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
    double temp;
    for (k = 1; k < 15; ++k) {
        temp = -x * x / k;
        coef *= temp;
        if (k % 3 == 0) {
            del = coef / (2. * k + 1.);
            e += del;
        }
    }
}
