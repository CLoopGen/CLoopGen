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
    for (i = 0; i < 13; i++) {
        if (r[i] > 0.0) {
            res12 += r[i] * cheb12[i];
        } else {
            res12 -= cheb12[i];
        }
    }
}
