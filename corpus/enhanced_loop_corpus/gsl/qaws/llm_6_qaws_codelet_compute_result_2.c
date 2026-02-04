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
    double temp_res = 0.0;
    for (i = 0; i < 25; i++) {
        temp_res = temp_res + r[i] * cheb24[i];
    }
    res24 += temp_res;
}
