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
    if (gamma == 1.0) {
        for (i = 0; i < 10; i++) {
            coeff[i] = inbuf[i] * fac;
        }
    } else {
        for (i = 0; i < 10; i++) {
            coeff[i] = inbuf[i] * fac;
            fac *= gamma;
        }
    }
}
