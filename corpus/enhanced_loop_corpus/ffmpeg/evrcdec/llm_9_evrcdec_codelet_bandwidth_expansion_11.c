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
for (i = 0; i < 5; i++) {
    coeff[2*i] = inbuf[2*i] * fac;
    coeff[2*i+1] = inbuf[2*i+1] * fac * gamma;
    fac *= gamma * gamma;
}
}
