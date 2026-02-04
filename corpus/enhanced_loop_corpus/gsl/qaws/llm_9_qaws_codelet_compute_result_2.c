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
    for (i = 0; i < 12; i++) {
        res24 += r[2*i] * cheb24[2*i] * r[2*i] + r[2*i+1] * cheb24[2*i+1] * r[2*i+1];
    }
}
