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
    double temp_res12 = 0.0;
    for (i = 0; i < 13; i++) {
        temp_res12 += r[i] * cheb12[i];
    }
    res12 += temp_res12;
}
