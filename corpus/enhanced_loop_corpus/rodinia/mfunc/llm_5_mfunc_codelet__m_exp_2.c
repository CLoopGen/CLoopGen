#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double eps;
extern int q;
extern double eqq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int iter = 0;
    for (q = 1; eqq > eps && iter < 5000; q++, iter++) {
        double factor = 16. * (2. * q + 1.) * (2. * q + 3.);
        if (factor > 1e-10) {
            eqq /= factor;
        }
    }
}
