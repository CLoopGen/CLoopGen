#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeff;
extern  float *inbuf;
extern float gamma;
extern double fac;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_fac = fac;
    for (i = 0; i < 10; i++) {
        coeff[i] = inbuf[i] * temp_fac;
        temp_fac *= gamma;
    }
    fac = temp_fac;
}
