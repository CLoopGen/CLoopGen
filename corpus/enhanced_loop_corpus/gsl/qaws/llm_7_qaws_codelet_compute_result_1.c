#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *r;
extern  double *cheb12;
extern size_t i;
extern double res12;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    res12 = 0.0;
    for (i = 0; i < 13; i += 2) {
        double prod1 = r[i] * cheb12[i];
        if (i + 1 < 13) {
            double prod2 = r[i + 1] * cheb12[i + 1];
            res12 += prod1 + prod2;
        } else {
            res12 += prod1;
        }
    }
}
