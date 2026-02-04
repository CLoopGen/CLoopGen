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
    for (i = 0; i < 10; i++) {
        double local_fac = fac;
        int j;
        for (j = 0; j < i; j++) {
            local_fac *= gamma;
        }
        coeff[i] = inbuf[i] * local_fac;
    }
}
