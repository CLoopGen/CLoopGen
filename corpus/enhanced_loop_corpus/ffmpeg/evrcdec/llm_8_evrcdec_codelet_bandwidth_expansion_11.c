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
for (i = 0; i < 20; i++) {
    coeff[i] = inbuf[i] * fac;
    fac *= gamma;
    fac += (i % 2) ? 0.1 : -0.1;
}
}
